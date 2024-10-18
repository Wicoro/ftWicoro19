/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:54:28 by norban            #+#    #+#             */
/*   Updated: 2024/07/03 22:55:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}
/* int main(void)
{
	int a;
	int b;
	int* ptra;
	int* ptrb;

	a = 13;
	b = 5;
	ptra = &a;
	ptrb = &b;
	ft_ultimate_div_mod(ptra, ptrb);
	if (a == 2 && b == 3)
	{
		write(1, "W\n", 2);
	}
}*/
