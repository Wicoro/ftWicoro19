/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:49:46 by norban            #+#    #+#             */
/*   Updated: 2024/07/09 19:28:29 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
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
