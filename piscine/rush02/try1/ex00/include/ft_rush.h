/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:33:44 by norban            #+#    #+#             */
/*   Updated: 2024/07/21 12:15:27 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

struct s_nb_dict
{
	char	*val;
	char	*name;
	int		val_size;
};

typedef struct s_nb_dict	t_nb_dict;

int			ft_strlen(char *str);
t_nb_dict	*ft_create_dictionnary(char *file);
char		**ft_split(char *str, char *sep);
int			ft_print_single_digit(t_nb_dict *map, char digit);
int			ft_print_tenth(t_nb_dict *map, char tenth, char unit);
int			ft_print_level(t_nb_dict *map, int pos, int nb);
void		ft_print_nb(t_nb_dict *map, char *nbr);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
void		ft_putchar(char c);

#endif
