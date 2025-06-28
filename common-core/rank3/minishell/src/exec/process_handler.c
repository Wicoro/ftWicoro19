/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:00:58 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/11 20:26:24 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	p_parent_signal_handler(t_datashell *data, int status, int *error)
{
	int	sig;

	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		data->return_val = 128 + sig;
		if (sig == SIGINT && *error == 0)
		{
			ft_putstr_fd("\n", 2);
			*error = 1;
		}
		if (sig == SIGQUIT && *error == 0)
		{
			ft_putstr_fd("Quit (core dumped)\n", 2);
			*error = 1;
		}
	}
	else if (WIFEXITED(status))
		data->return_val = WEXITSTATUS(status);
}

void	p_parent(pid_t *pids, int pipe_nbr, t_datashell *data)
{
	int	status;
	int	error;
	int	i;

	i = -1;
	error = 0;
	while (++i < pipe_nbr)
	{
		waitpid(pids[i], &status, 0);
		p_parent_signal_handler(data, status, &error);
	}
	restore_parent_signals();
	signal_parent();
}
