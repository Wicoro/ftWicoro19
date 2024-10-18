/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:42:06 by norban            #+#    #+#             */
/*   Updated: 2024/07/09 19:42:37 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
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
	int a = 0;
	int c = ft_iterative_factorial(a);
	printf("%d\n", c);
}*/
