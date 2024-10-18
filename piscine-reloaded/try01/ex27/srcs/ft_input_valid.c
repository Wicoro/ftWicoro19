/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:57:08 by norban            #+#    #+#             */
/*   Updated: 2024/10/07 17:46:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_display_file.h"

int	ft_input_missing(void)
{
	ft_putstr("File name missing.\n");
	return (0);
}

int	ft_input_too_much(void)
{
	ft_putstr("Too many arguments.\n");
	return (0);
}

int	ft_input_cannot_read(void)
{
	ft_putstr("Cannot read file.\n");
	return (0);
}

int	ft_is_input_valid(int ac, char **av)
{
	int	f;

	if (ac == 1)
		return (ft_input_missing());
	if (ac > 2)
		return (ft_input_too_much());
	f = open(av[1], 0);
	if (f == -1)
		return (ft_input_cannot_read());
	return (1);
}
