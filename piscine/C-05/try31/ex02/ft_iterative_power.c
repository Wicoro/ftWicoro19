/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:59:32 by norban            #+#    #+#             */
/*   Updated: 2024/07/14 14:01:08 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	mult;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	mult = nb;
	while (power > 1)
	{
		nb *= mult;
		power--;
	}
	return (nb);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_iterative_power(4, -5));
	printf("%d\n", ft_iterative_power(3, 0));
	printf("%d\n", ft_iterative_power(2, 1));
}*/
