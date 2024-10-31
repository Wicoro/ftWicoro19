/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:13:24 by norban            #+#    #+#             */
/*   Updated: 2024/07/09 14:35:49 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (nb % i != 0 && i <= nb / i)
		i++;
	if (nb % i == 0)
		return (0);
	return (1);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(-315));
	printf("%d\n", ft_is_prime(3));
	printf("%d\n", ft_is_prime(4219));
}*/
