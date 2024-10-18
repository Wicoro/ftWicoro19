/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:42:06 by norban            #+#    #+#             */
/*   Updated: 2024/07/08 13:47:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	while (i != 1)
	{
		nb *= i;
		i--;
	}
	return (nb);
}
/*#include <stdio.h>
int main()
{
	int a = 4;
	int b = 5;
	int c = ft_iterative_factorial(a);
	int d = ft_iterative_factorial(b);
	printf("%d\n", c);
	printf("%d\n", d);
}*/
