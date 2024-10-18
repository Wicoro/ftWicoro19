/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:36:43 by norban            #+#    #+#             */
/*   Updated: 2024/07/21 17:59:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

int	ft_print_single_digit(t_nb_dict *map, char digit)
{
	int	i;

	i = 0;
	while (map[i].name)
	{
		if (map[i].val[0] == digit && map[i].val[1] == '\0')
		{
			ft_putstr(map[i].name);
			write(1, " ", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_print_tenth2(t_nb_dict *map, char tenth, char unit)
{
	int	i;

	i = 0;
	while (map[i].name)
	{
		if (map[i].val[0] == tenth && map[i].val[1] == '0'
			&& map[i].val[2] == '\0')
		{
			ft_putstr(map[i].name);
			write(1, " ", 1);
			if (unit != '0')
				ft_print_single_digit(map, unit);
			return (1);
		}
		else if (tenth == '0' && map[i].val[0] == unit && map[i].val[1] == '\0')
		{
			return (ft_print_single_digit(map, unit));
		}
		i++;
	}
	return (0);
}

int	ft_print_tenth(t_nb_dict *map, char tenth, char unit)
{
	int	i;

	i = 0;
	while (map[i].name)
	{
		if (map[i].val[0] == tenth && map[i].val[1] == unit
			&& map[i].val[2] == '\0')
		{
			ft_putstr(map[i].name);
			write(1, " ", 1);
			return (1);
		}
		i++;
	}
	return (ft_print_tenth2(map, tenth, unit));
}

int	ft_print_level(t_nb_dict *map, int pos, int nb)
{
	int	i;

	i = 0;
	while (map[i].val_size != pos && map[i].name)
		i++;
	if (map[i].val_size == pos)
	{
		ft_putstr(map[i].name);
		if (nb > 1 && pos > 4)
			write(1, "s", 1);
		write(1, " ", 1);
		return (1);
	}
	return (0);
}
