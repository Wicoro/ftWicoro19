/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:28:12 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 15:59:20 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_heredoc_content(char *eof)
{
	char	*line;
	char	*str;
	int		interrupted;

	g_last_exit_status = 0;
	interrupted = 0;
	str = NULL;
	line = NULL;
	if (do_loop(line, &str, eof, &interrupted) == -1)
		return (NULL);
	free(line);
	if (interrupted)
		return (NULL);
	return (str);
}

static char	*finalize_heredoc_content(char *str, t_datashell *data)
{
	char	*tmp;
	char	*tmp2;
	char	*expanded;

	tmp = ft_strjoin(str, "\n");
	free(str);
	if (!tmp)
		return (NULL);
	tmp2 = ft_strdup(tmp);
	free(tmp);
	if (!tmp2)
		return (NULL);
	expanded = expander_str(tmp2, data);
	free(tmp2);
	return (expanded);
}

static int	write_to_pipe(t_hd_pipe *crt, char *str)
{
	if (write(crt->pipe[1], str, ft_strlen(str)) == -1)
		return (1);
	close(crt->pipe[1]);
	return (0);
}

static void	hd_child(t_hd_pipe *crt, char *eof, t_datashell *data, t_cmd *cmd)
{
	char	*str;
	char	*final_str;

	signal_heredoc();
	str = read_heredoc_content(eof);
	if (!str)
		free_exit(cmd, data, NULL, SIGINT);
	final_str = finalize_heredoc_content(str, data);
	if (!final_str)
		free_exit(cmd, data, NULL, 1);
	if (write_to_pipe(crt, final_str))
		free_exit(cmd, data, final_str, 1);
	free_exit(cmd, data, final_str, 0);
}

int	fill_hd_pipe(t_hd_pipe *crt, char *eof, t_datashell *data, t_cmd *cmd)
{
	pid_t	pid;
	int		status;
	int		sig;
	int		last_status;

	temporarily_ignore_signals();
	last_status = 0;
	pid = fork();
	if (pid == 0)
		hd_child(crt, eof, data, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		sig = WEXITSTATUS(status);
		last_status = 128 + sig;
	}
	restore_parent_signals();
	signal_parent();
	close(crt->pipe[1]);
	return (last_status);
}
