/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:40:23 by norban            #+#    #+#             */
/*   Updated: 2024/07/24 20:51:05 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

int	ft_process_arg_board(char *file_address)
{
	t_board	board;

	board = ft_extract_arg_board(file_address);
	if (board.map == 0)
		return (0);
	ft_find_bsq(board);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		f;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			f = open(av[i], 0);
			if (f == -1 || ft_process_arg_board(av[i]) == 0)
				ft_putstr("map error\n");
			close(f);
			i++;
		}
	}
	else
	{
		if (ft_extract_input_board() == 0)
			ft_putstr("map error\n");
	}
	system("leaks bsq");
}
