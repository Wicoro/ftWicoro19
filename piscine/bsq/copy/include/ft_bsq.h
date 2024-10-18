/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:28:20 by norban            #+#    #+#             */
/*   Updated: 2024/07/22 22:46:12 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BSQ_X
# define BSQ_Y
# define BSQ_SIZE

char	**ft_split(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
char	**ft_extract_board(char *file);
int		is_board_valid(char **board);

#endif
