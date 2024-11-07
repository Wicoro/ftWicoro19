/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:39:59 by norban            #+#    #+#             */
/*   Updated: 2024/11/07 11:23:15 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printunbr_base(char *base, long l, int len)
{
	int	tmp;

	if (l >= 16)
	{
		tmp = printunbr_base(base, l / 16, len);
		if (tmp == -1)
			return (-1);
		len = tmp;
		tmp = printunbr_base(base, l % 16, len);
		if (tmp == -1)
			return (-1);
		len = tmp;
	}
	else
	{
		if (printchar(base[l]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if ((i != j && base[i] == base[j])
				|| base[j] == 43 || base[j] == 45)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	printnbr_base(int nbr, char *base)
{
	unsigned int	l;
	int				len;
	int				tmp;
	int				mult;

	l = (unsigned int)nbr;
	len = 0;
	mult = 0;
	if (l < 0 && is_base_valid(base) == 1)
	{
		if (printchar('-') == -1)
			return (-1);
		l *= -1;
		mult = 1;
	}
	if (is_base_valid(base) == 1)
	{
		tmp = printunbr_base(base, l, len);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	return (len + mult);
}

/*#include <stdio.h>
int main()
{
	printf("\n%i\n", printnbr_base(123456, "0123456789abcdef"));
}*/
