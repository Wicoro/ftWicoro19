/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:00:18 by norban            #+#    #+#             */
/*   Updated: 2024/07/10 09:30:52 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_putnbr(char *base, int base_size, long l)
{
	char	nbr_char;

	if (l >= base_size)
	{
		ft_putnbr(base, base_size, l / base_size);
		ft_putnbr(base, base_size, l % base_size);
	}
	else
	{
		nbr_char = base[l];
		write(1, &nbr_char, 1);
	}
}

int	ft_is_base_valid(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	l;
	int		valid_base;

	l = nbr;
	base_size = ft_strlen(base);
	valid_base = ft_is_base_valid(base);
	if (l < 0 && valid_base == 1)
	{
		write(1, "-", 1);
		l *= -1;
	}
	if (base_size > 1 && valid_base == 1)
		ft_putnbr(base, base_size, l);
}
