/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:29:15 by norban            #+#    #+#             */
/*   Updated: 2024/07/15 17:34:22 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_in_base(char c, char *base);
char	*ft_convert_from_decimal(int nbr, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (-1);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || ft_is_space(base[j]) == 1
				|| base[j] == 43 || base[j] == 45)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_convert_to_decimal(char *nbr, char *base)
{
	int	res;
	int	i;
	int	mult;

	i = 0;
	mult = 1;
	res = 0;
	while (ft_is_space(nbr[i]) == 1)
		i++;
	while (nbr[i] == 43 || nbr[i] == 45)
	{
		if (nbr[i] == 45)
			mult *= -1;
		i++;
	}
	while (nbr[i] && ft_in_base(nbr[i], base) != -1)
	{
		res = (res * ft_strlen(base)) + ft_in_base(nbr[i], base);
		i++;
	}
	return (res * mult);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_base_10;

	if (ft_valid_base(base_to) == -1 || ft_valid_base(base_from) == -1)
		return (0);
	nbr_base_10 = ft_convert_to_decimal(nbr, base_from);
	nbr = ft_convert_from_decimal(nbr_base_10, base_to);
	return (nbr);
}
/*#include <stdio.h>
int main()
{
	char *base1 = "0123456789";
	char *base2 = "0123456";
	char *nbr = "42";

	nbr = ft_convert_base(nbr, base1, base2);
	printf("%s\n", nbr);
}*/
