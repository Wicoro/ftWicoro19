/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:44:57 by norban            #+#    #+#             */
/*   Updated: 2024/07/03 22:45:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int main(void)
{
	int a;
	int b;
	int c;
	int d;
	int* ptra;
	int* ptrb;

	a = 13;
	b = 5;
	ptra = &c;
	ptrb = &d;
	ft_div_mod(a, b, ptra, ptrb);
	if (c == 2 && d == 3)
	{
		write(1, "W\n", 2);
	}
}*/
