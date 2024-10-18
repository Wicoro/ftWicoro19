/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:37:50 by norban            #+#    #+#             */
/*   Updated: 2024/07/25 11:29:01 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*tab_res;

	i = 0;
	tab_res = malloc(sizeof(int) * length);
	if (!tab_res)
		return (0);
	while (i < length)
	{
		tab_res[i] = f(tab[i]);
		i++;
	}
	return (tab_res);
}

/*#include <stdio.h>
int	mult(int a)
{
	return (a * 2);
}

int main()
{
	int *tab = malloc(8 * sizeof(int));
	int j = 1;
	int k = 0;
	while (j < 9)
	{
		tab[k] = j;
		j++;
		k++;
	}
	int *tab_res = ft_map(tab, 8, &mult);

	int i = 0;
	while (i < 8)
	{
		printf("%d\n", tab_res[i]);
		i++;
	}
}*/
