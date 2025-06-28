/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:59:25 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 15:55:08 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_hd_empty(t_hd_pipe **hd_pipe)
{
	*hd_pipe = ft_calloc(1, sizeof(t_hd_pipe));
	if (!(*hd_pipe))
		return (1);
	(*hd_pipe)->next = NULL;
	(*hd_pipe)->prev = NULL;
	return (0);
}

static int	create_hd_not_empty(t_hd_pipe **crt)
{
	(*crt)->next = ft_calloc(1, sizeof(t_hd_pipe));
	if (!(*crt)->next)
		return (1);
	(*crt)->next->prev = (*crt);
	return (0);
}

static int	create_hd(t_hd_pipe **hd, char *eof, t_datashell *data, t_cmd *cmd)
{
	t_hd_pipe	*crt;
	int			status;

	if (!(*hd))
	{
		if (create_hd_empty(hd) == 1)
			return (1);
		crt = *hd;
	}
	else
	{
		crt = *hd;
		while (crt->next)
			crt = crt->next;
		if (create_hd_not_empty(&crt) == 1)
			return (1);
		crt = crt->next;
	}
	if (pipe(crt->pipe) != 0)
		return (free_hd_pipe(*hd), 1);
	cmd->hd_pipe = (*hd);
	status = fill_hd_pipe(crt, eof, data, cmd);
	if (status != 128)
		return (data->return_val = status, 1);
	return (0);
}

int	process_heredoc(t_cmd *cmd, t_datashell *data)
{
	int			i;
	t_hd_pipe	*hd_pipe;

	i = 0;
	hd_pipe = NULL;
	while (cmd->red_id[i] != 0)
	{
		if (cmd->red_id[i] == 1
			&& create_hd(&hd_pipe, cmd->red_file[i], data, cmd) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	close_hd(t_hd_pipe *hd_pipe)
{
	t_hd_pipe	*crt;
	t_hd_pipe	*old;

	crt = hd_pipe;
	while (crt)
	{
		if (crt->pipe[0] >= 0)
			close(crt->pipe[0]);
		if (crt->pipe[1] >= 0)
			close(crt->pipe[1]);
		old = crt;
		crt = crt->next;
		free(old);
		old = NULL;
	}
	hd_pipe = NULL;
}
