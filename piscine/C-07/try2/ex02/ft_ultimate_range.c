/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:00:58 by norban            #+#    #+#             */
/*   Updated: 2024/07/15 15:02:27 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;

	if (max < min)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	*range = (int *) malloc(sizeof(int) * (length));
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (length);
}
/*#include <stdio.h>
int	main()
{
	int tab[56];
	int	min = 0;
	int	max = 10;
	int	*ptr = &tab[56];
	printf("%d\n", ft_ultimate_range(&ptr, min, max));
}*/
