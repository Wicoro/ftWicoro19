/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:48:01 by norban            #+#    #+#             */
/*   Updated: 2024/07/24 23:13:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

t_board	ft_get_board_chars(t_board board, char *first_line)
{
	int	line_length;

	line_length = ft_strlen(first_line);
	board.empty = first_line[line_length - 3];
	board.obst = first_line[line_length - 2];
	board.full = first_line[line_length - 1];
	return (board);
}

t_board	ft_send_empty_map(t_board board)
{
	board.map = 0;
	return (board);
}

t_board	ft_input_board_first(char *line, t_board board, int *board_size)
{
	char	*map_size_str;
	int		i;
	int		j;

	board = ft_get_board_chars(board, line);
	map_size_str = ft_substring(line, ft_strlen(line) - 3);
	i = 0;
	j = ft_strlen(map_size_str);
	while (i < j)
	{
		if (map_size_str[i] < '0' || map_size_str[i] > '9')
			return (ft_send_empty_map(board));
		i++;
	}
	free(board.map);
	*board_size = ft_atoi(map_size_str);
	board.map = malloc(sizeof(char *) * (*board_size + 2));
	if (!board.map)
		return (ft_send_empty_map(board));
	board.map[0] = line;
	board.map[*board_size + 1] = 0;
	return (board);
}

t_board	ft_extract_arg_board(char *file_address)
{
	char	*file;
	char	**map;
	t_board	board;

	board.map = 0;
	file = ft_get_file(file_address);
	map = ft_split(file);
	if (!map)
		return (board);
	free(file);
	board.map = map;
	board = ft_get_board_chars(board, board.map[0]);
	board = is_board_valid(board);
	if (board.map == 0)
		return (board);
	board.map++;
	return (board);
}
