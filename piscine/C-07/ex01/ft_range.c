/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:00:58 by norban            #+#    #+#             */
/*   Updated: 2024/07/15 15:02:13 by norban           ###   ########.fr       */
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
