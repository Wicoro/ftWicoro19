/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:13:24 by norban            #+#    #+#             */
/*   Updated: 2024/07/21 18:13:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

char	*three_nbr(char *nbr, int *size)
{
	char	*new_nb;
	int		i;
	int		j;

	if (*size % 3 == 0)
		return (nbr);
	else
	{
		*size = *size + 1;
		new_nb = malloc(sizeof(char) * (*size + 1));
		if (!new_nb)
			return (0);
		i = 1;
		j = 0;
		while (i < *size)
		{
			new_nb[i] = nbr[j];
			i++;
			j++;
		}
		new_nb[0] = '0';
		new_nb[i] = '\0';
		return (three_nbr(new_nb, size));
	}
}

int	ft_print_text(t_nb_dict *map, char *three, int pos)
{
	if (three[0] != '0' && (ft_print_single_digit(map, three[0]) == 0
			|| ft_print_level(map, 3, ft_atoi(three)) == 0))
		return (0);
	if ((three[1] != '0' || three[2] != '0')
		&& ft_print_tenth(map, three[1], three[2]) == 0)
		return (0);
	if (pos > 3 && (three[0] != '0' || three[1] != '0' || three[2] != '0'))
	{
		if (ft_print_level(map, pos - 2, ft_atoi(three)) == 0)
			return (0);
	}
	return (1);
}

void	ft_print_nb(t_nb_dict *map, char *nbr)
{
	int		nbr_size;
	int		pos;
	char	*three;

	nbr_size = ft_strlen(nbr);
	nbr = three_nbr(nbr, &nbr_size);
	pos = nbr_size;
	three = malloc(sizeof(char) * 4);
	if (!three)
		return ;
	while (pos != 0)
	{
		three[0] = nbr[nbr_size - pos];
		three[1] = nbr[nbr_size - pos + 1];
		three[2] = nbr[nbr_size - pos + 2];
		three[3] = '\0';
		if (ft_print_text(map, three, pos) == 0)
		{
			ft_putstr("\33[2K\r");
			ft_putstr("Dict Error\n");
			return ;
		}
		pos -= 3;
	}
	write(1, "\n", 1);
}
