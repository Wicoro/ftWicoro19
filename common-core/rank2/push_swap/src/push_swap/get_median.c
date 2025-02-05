/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:02:27 by norban            #+#    #+#             */
/*   Updated: 2024/12/03 15:13:53 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_median(t_stack *stack, t_node **pivots, int count)
{
	t_node	*node;
	int		i;
	int		j;

	i = stack->size;
	node = stack->start;
	while (i > 0)
	{
		j = count;
		while (j > 0)
		{
			if (node->pos == (stack->size / (count + 1)) * j)
				pivots[j - 1] = node;
			j--;
		}
		node = node->next;
		i--;
	}
}
