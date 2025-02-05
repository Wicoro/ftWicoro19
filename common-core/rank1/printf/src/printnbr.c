/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:30:35 by norban            #+#    #+#             */
/*   Updated: 2024/11/07 11:04:47 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printnbr(int nb)
{
	long	l;
	int		i;
	int		tmp;

	i = 1;
	l = nb;
	if (l < 0)
	{
		if (printchar('-') == -1)
			return (-1);
		i++;
		l = -l;
	}
	if (l > 9)
	{
		tmp = printnbr(l / 10);
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

/*#include <stdio.h>
int main()
{
	printf("\n%d\n", printnbr(-200000));
}*/
