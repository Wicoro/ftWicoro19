/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:56:25 by norban            #+#    #+#             */
/*   Updated: 2025/06/10 17:43:09 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enable_ctrl_backslash(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		perror("tcgetattr");
	term.c_cc[VQUIT] = 28;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
	{
		perror("tcsetattr");
		return ;
	}
}

void	sigquit_child_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit\n", 2);
	fflush(stdout);
	exit(128 + SIGQUIT);
}

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, sigquit_child_handler);
	enable_ctrl_backslash();
}
