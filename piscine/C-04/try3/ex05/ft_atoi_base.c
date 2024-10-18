/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:06:45 by norban            #+#    #+#             */
/*   Updated: 2024/07/09 19:07:13 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_convert(char *base, int base_size, int nbr, int base_nbr)
{
	long	l;
	int		mult;

	l = nbr;
	mult = 1;
	if (l < 0)
	{
		mult = -1;
		nbr *= -1;
	}
	if (l >= base_size)
	{
		base_nbr = ft_convert(base, base_size, l / base_size, base_nbr);
		base_nbr = ft_convert(base, base_size, l % base_size, base_nbr);
	}
	else
	{
		base_nbr *= 10;
		base_nbr += base[l % base_size] - 48;
	}
	base_nbr *= mult;
	return (base_nbr);
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

int	ft_atoi(char *str)
{
	int	i;
	int	mult;
	int	nb;

	nb = 0;
	mult = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			mult *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	nb *= mult;
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	base_size;

	base_size = 0;
	while (str[base_size])
		base_size++;
	if (base_size > 1 && ft_is_base_valid(base) == 1)
	{
		nbr = ft_atoi(str);
		return (ft_convert(base, base_size, nbr, 0));
	}
	return (0);
}
