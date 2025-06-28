/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:45:02 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/14 15:54:29 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_child(t_datashell *data, char **cmd_tab, int *fd)
{
	char	**env;
	char	*path;

	signal_child();
	env = get_full_env(data->env_start);
	if (data->cmd_list->red_id[0])
	{
		if (in_out_handler(data->cmd_list) == -1)
			return (free_hd_pipe(data->cmd_list->hd_pipe), free_tab(env), -1);
		close(fd[0]);
		close(fd[1]);
	}
	if (!cmd_tab || !cmd_tab[0])
		return (-1);
	path = get_path(cmd_tab, env);
	close_redi(data, fd);
	if (!path)
		return (free_tab(env),
			ft_putstr_fd(cmd_tab[0], 2),
			ft_putstr_fd(": command not found\n", 2), -1);
	if (execve(path, cmd_tab, env) == -1)
		return (perror("maxi-total: not executable"),
			free(path), free_tab(env), -1);
	return (0);
}

static void	do_parent(pid_t pid, t_datashell *data, int *fd)
{
	int	status;
	int	sig;

	waitpid(pid, &status, 0);
	restore_parent_signals();
	close_redi(data, fd);
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		data->return_val = 128 + sig;
		if (sig == SIGINT)
			ft_putstr_fd("\n", 2);
		else if (sig == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
	}
	else if (WIFEXITED(status))
		data->return_val = WEXITSTATUS(status);
	signal_parent();
}

static int	process_exec(t_datashell *data, char **cmd, int fd[2])
{
	pid_t	pid;

	temporarily_ignore_signals();
	pid = fork();
	if (pid == 0)
	{
		if (do_child(data, cmd, fd) == -1)
		{
			close_redi(data, fd);
			free_minishell(data);
			exit(127);
		}
	}
	do_parent(pid, data, fd);
	return (0);
}

static int	exec_one(t_datashell *data)
{
	char	**cmd_tab;
	int		fd[2];

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	cmd_tab = data->cmd_list->cmd_tab;
	if (!cmd_tab)
		return (-1);
	if (do_builtin(cmd_tab, data, data->cmd_list) == 0)
		return (close_redi(data, fd), 0);
	if (process_exec(data, cmd_tab, fd))
		return (1);
	return (0);
}

int	exec_line(t_datashell *data)
{
	if (!data->cmd_list->next)
		return (exec_one(data));
	else
		return (exec_pipe(data));
}
