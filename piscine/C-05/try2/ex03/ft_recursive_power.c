/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:10:43 by norban            #+#    #+#             */
/*   Updated: 2024/07/09 14:31:26 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
		nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
/*#include <stdio.h>
int main()
{
	printf("%d", ft_recursive_power(2, 4));
	printf("%d", ft_recursive_power(1, 4));
	printf("%d", ft_recursive_power(0, 4));
	printf("%d", ft_recursive_power(2, 0));
	printf("%d", ft_recursive_power(2, 1));
}*/
