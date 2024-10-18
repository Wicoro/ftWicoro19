/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:31:14 by norban            #+#    #+#             */
/*   Updated: 2024/07/03 18:20:15 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puchar(char c)
{

}

void	ft_paste_numbers(int a)
	int b;

	b = a + 1;
	while (b < 10)
	{
		ft_putchar(a + '0');
		ft_putchar(b + '0');
	}

void	ft_print_combn(int n)
{
	int a;

	a = 0;
	while (a < 10)
	{
		ft_paste_numbers(a);
	}
}
