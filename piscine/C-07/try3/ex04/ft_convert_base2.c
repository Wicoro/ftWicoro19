/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:54:41 by norban            #+#    #+#             */
/*   Updated: 2024/07/15 17:33:59 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *base);

int	ft_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_getsize(int nbr, int base_size)
{
	int	i;

	if (nbr < 0)
		nbr = -nbr;
	i = 0;
	while (nbr / base_size != 0)
	{
		i++;
		nbr /= base_size;
	}
	i += 2;
	return (i);
}

char	*ft_convert_from_decimal(int nbr, char *base)
{
	int		size;
	char	*str;
	int		i;
	int		mod;

	size = ft_getsize(nbr, ft_strlen(base));
	if (nbr < 0)
		size++;
	str = (char *) malloc(sizeof(char) * size);
	if (nbr < 0)
	{
		str[0] = '-';
		i = 1;
		nbr *= -1;
	}
	else
		i = 0;
	while (i < size - 1)
	{
		nbr /= ft_strlen(base);
		str[i] = base[nbr % ft_strlen(base)];
		i++;
	}
	str[size - 1] = '\0';
	return (str);
}
