/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:38:48 by norban            #+#    #+#             */
/*   Updated: 2025/04/16 16:40:36 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;

	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigquit_handler(int sig)
{
	(void)sig;
}

void disable_ctrl_backslash(void)
{
	struct termios term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}

void	signal_handler(void)
{
	struct sigaction sa_sigint;
	struct sigaction sa_sigquit;

    sa_sigint.sa_handler = sigint_handler;
    sigemptyset(&sa_sigint.sa_mask);
    sigaddset(&sa_sigint.sa_mask, SIGINT);
    sa_sigint.sa_flags = 0;
	
    sa_sigquit.sa_handler = sigquit_handler;
    sigemptyset(&sa_sigquit.sa_mask);
    sigaddset(&sa_sigquit.sa_mask, SIGQUIT);
    sa_sigquit.sa_flags = 0;
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
	disable_ctrl_backslash();
}