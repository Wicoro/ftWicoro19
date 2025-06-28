/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:49:52 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/13 19:57:29 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_counter(t_cmd *cmd)
{
	t_cmd	*crt;
	int		i;

	i = 0;
	crt = cmd;
	while (crt)
	{
		i++;
		crt = crt->next;
	}
	return (i);
}

int	pipe_setter(int	**pipe_tab, int pipe_nbr)
{
	int	i;

	i = 0;
	while (i < pipe_nbr - 1)
	{
		pipe_tab[i] = malloc(2 * sizeof(int));
		if (!pipe_tab[i])
			return (1);
		if (pipe(pipe_tab[i]) == -1)
			return (1);
		i++;
	}
	pipe_tab[i] = NULL;
	return (0);
}

void	free_itab(int **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	close_fd(int **pipe_tab)
{
	int	i;

	i = 0;
	while (pipe_tab[i])
	{
		close(pipe_tab[i][0]);
		close(pipe_tab[i][1]);
		i++;
	}
}

int	check_builtin(t_datashell *data, char **cmd_tab, t_cmd *cmd)
{
	int		fd[2];

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	if (do_builtin(cmd_tab, data, cmd) == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close_hd(cmd->hd_pipe);
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
