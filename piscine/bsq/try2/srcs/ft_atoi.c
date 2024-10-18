/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:45:02 by norban            #+#    #+#             */
/*   Updated: 2024/07/23 14:27:20 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*#include <stdio.h>
int main()
{
	char	*str = "- +264888a";
	printf("%d\n", ft_atoi(str));
}*/
