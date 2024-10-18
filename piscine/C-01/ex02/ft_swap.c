/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:41:14 by norban            #+#    #+#             */
/*   Updated: 2024/07/11 15:44:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
/*int main(void)
{
	int a;
	int b;
	int* ptra;
	int* ptrb;

	a = 5;
	b = 10;
	ptra = &a;
	ptrb = &b;
	ft_swap(ptra, ptrb);
	if (b == 5 && a == 10)
	{
		write(1, "W\n", 2);
	}
}*/
