/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_board_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:11:13 by norban            #+#    #+#             */
/*   Updated: 2024/07/24 22:38:15 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

int	ft_is_board_chars_valid(t_board board)
{
	int		line_length;

	line_length = ft_strlen(board.map[0]);
	if (board.full == board.empty
		|| board.full == board.obst
		|| board.empty == board.obst)
		return (0);
	return (1);
}

t_board	ft_false_board(t_board board)
{
	board.map = 0;
	return (board);
}

t_board	ft_check_line_c(t_board board)
{
	char	*line_c_str;
	int		line_c_int;
	int		j;

	line_c_str = ft_substring(board.map[0], ft_strlen(board.map[0]) - 3);
	j = 0;
	while (line_c_str[j])
	{
		if (line_c_str[j] < '0' || line_c_str[j] > '9')
			return (ft_false_board(board));
		j++;
	}
	line_c_int = ft_atoi(line_c_str);
	free(line_c_str);
	if (line_c_int != board.height)
		return (ft_false_board(board));
	return (board);
}

t_board	is_board_valid(t_board board)
{
	int		i;
	int		j;

	board.width = ft_strlen(board.map[1]);
	if (ft_is_board_chars_valid(board) == 0)
		return (ft_false_board(board));
	i = 1;
	while (board.map[i])
	{
		j = 0;
		while (board.map[i][j])
		{
			if (board.map[i][j] != board.empty && board.map[i][j] != board.obst)
				return (ft_false_board(board));
			j++;
		}
		if (board.width == 0 || j != board.width)
			return (ft_false_board(board));
		i++;
	}
	board.height = i - 1;
	if (i == 0)
		return (ft_false_board(board));
	return (ft_check_line_c(board));
}
