/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:04:23 by norban            #+#    #+#             */
/*   Updated: 2024/07/18 23:16:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;

	sort = 1;
	i = 0;
	while (i < length - 1 && sort == 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			sort = 0;
		i++;
	}
	if (sort == 0)
	{
		i = 0;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
/*
int cmp(int a, int b)
{
	return (a - b);
}
#include <stdio.h>
int main()
{
	int tab[] = {5, 4, 3, 2, 1};

	printf("%d\n", ft_is_sort(tab, 5, &cmp));
}*/
