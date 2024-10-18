/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:36:00 by norban            #+#    #+#             */
/*   Updated: 2024/07/09 19:37:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	while (i * i != nb && nb / i >= i)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(1));
}*/
