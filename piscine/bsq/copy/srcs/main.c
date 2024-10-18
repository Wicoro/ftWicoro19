/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:40:23 by norban            #+#    #+#             */
/*   Updated: 2024/07/22 23:13:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

int	ft_process_board(char *file_address)
{
	char	**board;
	char	empty;
	char	obstacle;
	char	full;

	board = ft_extract_board(av[i], &empty, &obstacle, &full);
	if (board == 0)
		return (0);
	ft_find_bsq(board);
}

int	main(int ac, char **av)
{
	int		i;
	int		f;

	i = 1;
	while (av[i])
	{
		f = open(av[i], 0);
		if (f == -1)
			ft_putstr("map error");
		else
		{
			close(f);
			if (ft_process_board(av[i] == 0))
				ft_putstr("map error");
		}
		i++;
	}
}
