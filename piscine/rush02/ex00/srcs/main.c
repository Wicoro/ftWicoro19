/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:24:10 by norban            #+#    #+#             */
/*   Updated: 2024/07/21 12:06:26 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"
#include <stdio.h>

int	is_nbr_valid(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] && (nbr[i] < '0' || nbr[i] > '9'))
		{
			ft_putstr("Error : The inputed number is invalid\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	invalid_input(void)
{
	ft_putstr("Error : The number of input is invalid\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_nb_dict	*map;
	char		*file;
	char		*nbr;

	nbr = av[1];
	if (ac == 3)
	{
		file = av[1];
		nbr = av[2];
	}
	else if (ac != 2)
		return (invalid_input());
	else
		file = "numbers.dict";
	if (is_nbr_valid(nbr) == 1)
		return (0);
	map = ft_create_dictionnary(file);
	while (nbr[0] == '0')
		nbr++;
	if (nbr[0] == '\0')
		write(1, "0\n", 2);
	else
		ft_print_nb(map, nbr);
	free(map);
}
