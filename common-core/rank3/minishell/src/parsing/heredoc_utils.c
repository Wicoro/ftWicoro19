/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:47:25 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 14:32:56 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_heredoc_line(char *str, char *line)
{
	char	*tmp;
	char	*new_str;

	tmp = NULL;
	new_str = NULL;
	if (str)
	{
		tmp = ft_strdup(str);
		if (!tmp)
			return (free(str), NULL);
		free(str);
		new_str = ft_strjoin_nl(tmp, line);
		free(tmp);
	}
	else
	{
		free(str);
		new_str = ft_strdup(line);
	}
	if (!new_str)
		return (NULL);
	return (new_str);
}

static void	write_warning(char *eof)
{
	ft_putstr_fd("maxi-total: warning: here-document", 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(eof, 2);
	ft_putstr_fd("')", 2);
}

static int	free_str(char *str)
{
	free(str);
	str = NULL;
	return (1);
}

int	do_loop(char *line, char **str, char *eof, int *interrupted)
{
	while (1)
	{
		line = readline("> ");
		if (g_last_exit_status == 130)
		{
			*interrupted = free_str(*str);
			break ;
		}
		if (!line)
		{
			write_warning(eof);
			break ;
		}
		if (ft_strlen(line) == ft_strlen(eof)
			&& ft_strncmp(line, eof, ft_strlen(line)) == 0)
			break ;
		(*str) = append_heredoc_line((*str), line);
		if (!(*str))
			return (free(line), signal_parent(), -1);
		free(line);
	}
	return (0);
}
