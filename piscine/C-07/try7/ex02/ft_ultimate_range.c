/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:00:58 by norban            #+#    #+#             */
/*   Updated: 2024/07/16 18:17:21 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	*range = malloc(sizeof(int) * (length));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (0 < max - min)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (length);
}
/*#include <stdio.h>
int	main()
{
	int tab[100];
	int	min = 10;
	int	max = 99;
	int	*ptr = &tab[0];
	int i = 0;
	ft_ultimate_range(&ptr, min, max);
	while (i < max - min)
	{
		printf("%d\n", ptr[i]);
		i++;
	}
}*/
