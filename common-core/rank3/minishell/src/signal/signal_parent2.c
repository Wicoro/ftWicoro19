/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parent2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:14:36 by norban            #+#    #+#             */
/*   Updated: 2025/06/11 20:41:06 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	temporarily_ignore_signals(void)
{
	struct sigaction	ignore;

	ignore.sa_handler = SIG_IGN;
	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags = 0;
	if (sigaction(SIGINT, &ignore, NULL) == -1
		|| sigaction(SIGQUIT, &ignore, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	restore_parent_signals(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = SIG_DFL;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sa_quit.sa_handler = SIG_DFL;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	if (sigaction(SIGINT, &sa_int, NULL) == -1
		|| sigaction(SIGQUIT, &sa_quit, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	sigint_handler_heredoc(int sig)
{
	(void)sig;
	g_last_exit_status = 130;
	printf("\n");
	close(0);
}

void	signal_heredoc(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = sigint_handler_heredoc;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sa_sigquit.sa_handler = SIG_DFL;
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigquit.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
	{
		perror("sigaction failed");
		exit(1);
	}
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
	{
		perror("sigaction failed");
		exit(1);
	}
}
