/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:14:21 by norban            #+#    #+#             */
/*   Updated: 2024/12/17 18:52:10 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	re_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int tab[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (tab[j] < pivot)
		{
			i++;
			re_swap(&(tab[i]), &(tab[j]));
		}
		j++;
	}
	re_swap(&(tab[i + 1]), &(tab[high]));
	return (i + 1);
}

void	quicksort(int tab[], int low, int high)
{
	int	part;

	if (low < high)
	{
		part = partition(tab, low, high);
		quicksort(tab, low, part - 1);
		quicksort(tab, part + 1, high);
	}
}
