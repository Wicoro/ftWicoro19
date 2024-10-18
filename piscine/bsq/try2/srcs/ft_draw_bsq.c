/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:52:49 by mokariou          #+#    #+#             */
/*   Updated: 2024/07/24 19:35:26 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

void	ft_print_board(t_board board)
{
	int	i;

	i = 0;
	while (board.map[i])
	{
		ft_putstr(board.map[i]);
		free(board.map[i]);
		ft_putstr("\n");
		i++;
	}
}

void	ft_draw_bsq(t_board board, int bsq_x, int bsq_y, int size)
{
	int	max_x;
	int	max_y;
	int	bsq_ini_x;

	bsq_ini_x = bsq_x;
	max_x = bsq_x + size;
	max_y = bsq_y + size;
	while (bsq_y < max_y)
	{
		bsq_x = bsq_ini_x;
		while (bsq_x < max_x)
		{
			board.map[bsq_y][bsq_x] = board.full;
			bsq_x++;
		}
		bsq_y++;
	}
	ft_print_board(board);
}
