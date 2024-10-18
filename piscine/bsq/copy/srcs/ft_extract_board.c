/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:48:01 by norban            #+#    #+#             */
/*   Updated: 2024/07/22 23:15:01 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

char	*ft_fill_file(char *file, char *file_address)
{
	int		f;
	int		r;
	char	a;
	int		i;

	f = open(file_address, 0);
	r = read(f, &a, 1);
	i = 0;
	while (r)
	{
		file[i] = a;
		r = read(f, &a, 1);
		i++;
	}
	file[i] = '\0';
	return (file);
}

char	*ft_get_file(char *file_address)
{
	int		f;
	int		r;
	char	a;
	int		file_size;
	char	*file;

	file_size = 0;
	f = open(file_address, 0);
	r = read(f, &a, 1);
	while (r)
	{
		file_size++;
		r = read(f, &a, 1);
	}
	close(f);
	file = malloc(sizeof(char) * (file_size + 1));
	if (!file)
		return (0);
	return (ft_fill_file(file, file_address));
}

void	ft_get_board_chars(char **board, char *e, char *o, char *f)
{
	int	line_length;

	line_length = ft_strlen(board[1]);
	*e = board[1][line_length - 3];
	*o = board[1][line_length - 2];
	*f = board[1][line_length - 1];
}

char	**ft_extract_board(char *file_address, char *e, char *o, char *f)
{
	char	*file;
	char	**board;

	file = ft_get_file(file_address);
	board = ft_split(file_address);
	free(file);
	if (is_board_valid(board) == 0)
		return (0);
	ft_get_board_chars(board, empty, obstacle, full);
	board++;
	return (board);
}
