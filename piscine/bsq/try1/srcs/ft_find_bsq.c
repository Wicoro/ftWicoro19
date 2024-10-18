/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:52:49 by mokariou          #+#    #+#             */
/*   Updated: 2024/07/24 20:51:53 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

int	ft_check_y(t_board board, int x, int y, int crent_siz)
{
	int	i;

	i = x + crent_siz;
	while (x < i && x < board.width && y + crent_siz < board.height
		&& board.map[y + crent_siz][x] != board.obst)
		x++;
	if (y + crent_siz >= board.height
		|| board.map[y + crent_siz][x] == board.obst)
		return (0);
	return (1);
}

int	ft_check_x(t_board board, int x, int y, int crent_siz)
{
	int	i;

	i = y + crent_siz;
	while (y < i && y < board.height && x + crent_siz < board.width
		&& board.map[y][x + crent_siz] != board.obst)
		y++;
	if (x + crent_siz >= board.width
		|| board.map[y][x + crent_siz] == board.obst)
		return (0);
	return (1);
}

int	ft_check_bsq(t_board board, int po_x, int po_y, int bsq_size)
{
	int	crent_siz;
	int	loop_break;

	loop_break = 0;
	crent_siz = 1;
	while (po_y + crent_siz <= board.height
		&& po_x + crent_siz <= board.width
		&& loop_break == 0)
	{
		if (ft_check_y(board, po_x, po_y, crent_siz) == 1
			&& ft_check_x(board, po_x, po_y, crent_siz) == 1)
			crent_siz++;
		else
		{
			if (crent_siz > bsq_size)
				return (crent_siz);
			loop_break = 1;
		}
	}
	return (0);
}

void	ft_find_bsq(t_board board)
{
	int	bsq_x;
	int	bsq_y;
	int	po_x;
	int	po_y;
	int	bsq_size;

	bsq_size = 0;
	po_y = 0;
	while (po_y < board.height - bsq_size)
	{
		po_x = 0;
		while (po_x < board.width - bsq_size)
		{
			if (board.map[po_y][po_x] == board.empty
				&& ft_check_bsq(board, po_x, po_y, bsq_size) > bsq_size)
			{
				bsq_x = po_x;
				bsq_y = po_y;
				bsq_size = ft_check_bsq(board, po_x, po_y, bsq_size);
			}
			po_x++;
		}
		po_y++;
	}
	ft_draw_bsq(board, bsq_x, bsq_y, bsq_size);
}
