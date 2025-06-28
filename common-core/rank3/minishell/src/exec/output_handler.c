/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:41:07 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/13 16:28:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	last_output(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd->red_id[i] != 0)
	{
		if (cmd->red_id[i] == REPLACEF || cmd->red_id[i] == ADDF)
			j = i;
		i++;
	}
	return (j);
}

int	output_handler2(int i, t_cmd *cmd, int *fd)
{
	if (cmd->red_id[i] == ADDF)
	{
		*fd = open(cmd->red_file[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (*fd == -1)
		{
			ft_putstr_fd("maxi-total: ", 2);
			ft_putstr_fd(cmd->red_file[i], 2);
			perror(": ");
			return (-1);
		}
		if (i == last_output(cmd))
			dup2(*fd, STDOUT_FILENO);
		close(*fd);
	}
	return (0);
}

int	output_handler(t_cmd *cmd)
{
	int	i;
	int	fd;

	i = -1;
	fd = 0;
	while (cmd->red_id[++i] != 0)
	{
		if (cmd->red_id[i] == REPLACEF)
		{
			fd = open(cmd->red_file[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (fd == -1)
			{
				ft_putstr_fd("maxi-total: ", 2);
				ft_putstr_fd(cmd->red_file[i], 2);
				perror(": ");
				return (-1);
			}
			if (i == last_output(cmd))
				dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		if (output_handler2(i, cmd, &fd) == -1)
			return (-1);
	}
	return (fd);
}
