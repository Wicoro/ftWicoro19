/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:28:54 by norban            #+#    #+#             */
/*   Updated: 2024/07/04 12:03:25 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	restart;
	int	temp;

	index = 0;
	restart = 0;
	while (index <= size - 2)
	{
		if (tab[index] > tab[index + 1])
		{
			restart = 1;
			temp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = temp;
		}
		index++;
	}
	if (restart == 1)
	{
		ft_sort_int_tab(tab, size);
	}
}
/*int main(void)
{
	int tab[] = {5, 4, 9, 6, 3, 2};
	int tabref[] = {2, 3, 4, 5, 6, 9};
	int* ptr;

	ptr = &tab[0];
	ft_sort_int_tab(ptr, 6);
	if (tab[1] == tabref[1])
	{
		write(1, "W\n", 2);
	}
}*/	
