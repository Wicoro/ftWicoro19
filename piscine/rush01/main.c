/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:20:54 by norban            #+#    #+#             */
/*   Updated: 2024/07/13 17:28:12 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rush.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	is_arg_valid(char *arg)
{
	int	i;

	if (ft_strlen(arg) != 31)
		return (0);
	if (!(arg[0] >= 49 && arg[0] <= 52))
		return (0);
	i = 1;
	while (i <= 29)
	{
		if ((!(arg[i + 1] >= 49 && arg[i + 1] <= 52)
				&& arg[i + 1]) || (arg[i] != 32))
			return (0);
		i += 2;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	**tab;

	if (ac != 2 || is_arg_valid(av[1]) == 0)
	{
		ft_putstr("Saisie des arguments invalides.\n");
		return (0);
	}
	tab = 0;
	tab = ft_skyscrapper(av[1]);
	ft_print_result(tab, av[1]);
}
