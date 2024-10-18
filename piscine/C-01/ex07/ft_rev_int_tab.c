/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:06:12 by norban            #+#    #+#             */
/*   Updated: 2024/07/11 15:47:31 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = size -1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}
#include <stdio.h>
int main(void)
{
    int a[] = {1, -2, 3, -4, -5, 6, 7};
    ft_rev_int_tab(a, 7);
	int i = 0;
	while (i < 7)
	{
		printf("%d, ", a[i]);
		i++;
	}
}
