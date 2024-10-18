/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:47:30 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 09:32:54 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*tab;
	int	i;

	if (max <= min)
		return (NULL);
	range = max - min;
	tab = (int *) malloc(sizeof(int) * range);
	if (!tab)
		return (NULL);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/*#include <stdio.h>
int	main()
{
	int i = 0;

	while (i < 55)
	{
		printf("%d\n", ft_range(-20, 35)[i]);
		i++;
	}
}*/
