/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:30:35 by norban            #+#    #+#             */
/*   Updated: 2024/11/07 10:55:22 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printunbr(unsigned int nb)
{
	unsigned long	l;
	int				i;
	int				tmp;

	i = 1;
	l = nb;
	if (l > 9)
	{
		tmp = printunbr(l / 10);
		if (tmp == -1)
			return (-1);
		i += tmp;
		if (printchar(l % 10 + '0') == -1)
			return (-1);
	}
	else if (printchar(l + '0') == -1)
		return (-1);
	return (i++);
}
