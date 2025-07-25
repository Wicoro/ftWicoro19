/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:45:36 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 11:46:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb >= 13)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	else
		nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_factorial(0));
}*/