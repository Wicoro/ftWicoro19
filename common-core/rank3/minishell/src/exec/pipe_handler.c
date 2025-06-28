/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:29:25 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/14 15:54:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call_handler(t_cmd *cmd)
{
	if (in_out_handler(cmd) == -1)
		return (-1);
	return (0);
}

void	ffree(char **cmd_tab, int **p_tab, char **env, char *path)
{
	if (cmd_tab)
		free_tab(cmd_tab);
	if (env)
		free_tab(env);
	if (p_tab)
		free_itab(p_tab);
	if (path)
		free(path);
}

static void	ft_free_exit(pid_t *pids, int **p_tab, t_datashell *data)
{
	free(pids);
	free_itab(p_tab);
	free_minishell(data);
	exit(0);
}

static void	do_exec(t_datashell *data, pid_t *pids, int **p_tab, int p_nbr)
{
	int		i;
	t_cmd	*crt;

	i = 0;
	crt = data->cmd_list;
	while (crt)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			if (p_child(p_tab, crt, i, data) == -1)
				ft_free_exit(pids, p_tab, data);
		}
		crt = crt->next;
		i++;
	}
	close_fd(p_tab);
	p_parent(pids, p_nbr, data);
}

int	exec_pipe(t_datashell *data)
{
	pid_t	*pids;
	int		**pipe_tab;
	int		pipe_nbr;

	pipe_nbr = pipe_counter(data->cmd_list);
	pipe_tab = malloc(pipe_nbr * sizeof(int *));
	if (!pipe_tab)
		return (1);
	if (pipe_setter(pipe_tab, pipe_nbr))
		return (free_itab(pipe_tab), 1);
	pids = malloc(sizeof(pid_t) * pipe_nbr);
	if (!pids)
		return (free_itab(pipe_tab), 1);
	temporarily_ignore_signals();
	do_exec(data, pids, pipe_tab, pipe_nbr);
	return (free(pids), free_itab(pipe_tab), 0);
}
