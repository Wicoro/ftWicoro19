/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_input_board.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:59:40 by norban            #+#    #+#             */
/*   Updated: 2024/07/24 23:12:41 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

t_board	ft_return_empty_board(t_board board)
{
	board.map = 0;
	return (board);
}

t_board	ft_fill_board(t_board board, int *board_size)
{
	int		i;
	int		r;
	char	a;
	char	*line;

	i = 1;
	line = malloc(sizeof(char));
	line[0] = '\0';
	while (i < *board_size + 1)
	{
		r = read(0, &a, 1);
		if (a == '\n')
		{
			board.map[i] = line;
			line = malloc(sizeof(char));
			if (!line)
				return (ft_return_empty_board(board));
			line[0] = '\0';
			i++;
		}
		else
			line = ft_strjoin(line, a);
	}
	return (board);
}

int	ft_process_input_board(t_board board, char *line)
{
	int		board_size;

	board = ft_input_board_first(line, board, &board_size);
	if (!board.map || board_size == 0)
		return (0);
	board = ft_fill_board(board, &board_size);
	board = is_board_valid(board);
	if (!board.map)
		return (0);
	board.map++;
	ft_find_bsq(board);
	free(line);
	return (1);
}

int	ft_extract_input_board(void)
{
	int		r;
	char	a;
	char	*line;
	t_board	board;

	line = malloc(sizeof(char));
	if (!line)
		return (0);
	r = read(0, &a, 1);
	while (a != '\n')
	{
		line = ft_strjoin(line, a);
		r = read(0, &a, 1);
	}
	board.map = malloc(sizeof(char *));
	if (!board.map || ft_strlen(line) < 4)
		return (0);
	if (ft_process_input_board(board, line) == 0)
		return (0);
	return (1);
}
