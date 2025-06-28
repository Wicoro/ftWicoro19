/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:18:31 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/14 15:46:50 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	last_input(t_cmd *cmd)
{
	int	i;
	int	j;
	int	hd;

	i = 0;
	j = 0;
	hd = 0;
	while (cmd->red_id[i] != 0)
	{
		if (cmd->red_id[i] == OPENF || cmd->red_id[i] == HEREDOC)
		{
			j = i;
			if (cmd->red_id[i] == HEREDOC)
				hd++;
		}
		i++;
	}
	if (hd > 0)
		cmd->hd_pipe = NULL;
	return (j);
}

static void	do_hd(t_cmd *cmd, int i)
{
	t_hd_pipe	*crt;

	crt = cmd->hd_pipe;
	if (i == last_input(cmd))
		dup2(crt->pipe[0], STDIN_FILENO);
	close(crt->pipe[0]);
	close(crt->pipe[1]);
	crt = crt->next;
}

int	input_handler(t_cmd *cmd)
{
	int	i;
	int	fd;

	i = 0;
	while (cmd->red_id[i] != 0)
	{
		if (cmd->red_id[i] == OPENF)
		{
			fd = open(cmd->red_file[i], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr_fd("maxi-total: ", 2);
				ft_putstr_fd(cmd->red_file[i], 2);
				perror(": ");
				return (-1);
			}
			if (i == last_input(cmd))
				dup2(fd, STDIN_FILENO);
			close(fd);
		}
		if (cmd->red_id[i] == HEREDOC)
			do_hd(cmd, i);
		i++;
	}
	return (0);
}
