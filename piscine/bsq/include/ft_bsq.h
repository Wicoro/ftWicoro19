/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:28:20 by norban            #+#    #+#             */
/*   Updated: 2024/07/24 15:50:56 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_board
{
	char	**map;
	char	empty;
	char	obst;
	char	full;
	int		height;
	int		width;
}	t_board;

char	**ft_split(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
t_board	ft_extract_arg_board(char *file);
t_board	ft_input_board_first(char *file, t_board board, int *board_size);
int		ft_extract_input_board(void);
t_board	is_board_valid(t_board board);
char	*ft_substring(char *str, int end);
int		ft_atoi(char *str);
char	*ft_get_file(char *file_address);
char	*ft_strjoin(char *str, char c);
void	ft_find_bsq(t_board board);
void	ft_draw_bsq(t_board board, int bsq_x, int bsq_y, int bsq_size);

#endif
