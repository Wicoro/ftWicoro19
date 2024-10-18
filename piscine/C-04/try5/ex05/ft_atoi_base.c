/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:06:45 by norban            #+#    #+#             */
/*   Updated: 2024/07/10 09:50:20 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_is_in_base(char c, char *base)
{
	int i;
	int check;

	check = 0;
	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if ((i != j && base[i] == base[j])
				|| base[j] == 43 || base[j] == 45
				|| (base[j] >= 9 && base[j] <= 13))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		mult;
	long	nb;

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
	while (str[i] && ft_is_in_base(str[i], base) != -1)
	{
		nb = (nb * ft_strlen(base)) + ft_is_in_base(str[i], base);
		i++;
	}
	nb *= mult;
	return (nb);
}
/*#include <stdio.h>
int main()
{
	char* base = "0";
	printf("%d\n", ft_atoi_base("4DC", base));
}*/
