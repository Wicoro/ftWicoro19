/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_board_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:11:13 by norban            #+#    #+#             */
/*   Updated: 2024/07/22 23:06:46 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_size(char **board)
{
	int	board_length;

	board_length = 0;
	while (board[1] && board[1][board_length])
		board_length++;
	return (board_length);
}

void	ft_get_valid_board_chars(char **board, char *empty, char *obstacle)
{
	int	line_length;

	line_length = ft_strlen(board[1]);
	*empty = board[1][line_length - 3];
	*obstacle = board[1][line_length - 2];
}

int	is_board_valid(char **board)
{
	int		i;
	int		j;
	int		board_length;
	char	empty;
	char	obstacle;

	board_length = ft_check_size(board);
	if (board_length == 0)
		return (0);
	ft_get_valid_board_chars(board, &empty, &obstacle);
	i = 1;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] != empty && board[i][j] != obstacle)
				return (0);
			j++;
		}
		if (j != board_length)
			return (0);
		i++;
	}
	return (1);
}
