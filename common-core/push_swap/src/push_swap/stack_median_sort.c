/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_median_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:57:40 by norban            #+#    #+#             */
/*   Updated: 2024/12/16 15:19:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	middle_median_pusher(t_stacks *stacks, t_node *node, int i, int j)
{
	int	k;

	k = stacks->stack_a->size;
	while (k > 0)
	{
		node = stacks->stack_a->start;
		if (node->pos <= stacks->pivots[j]->pos
			&& node->pos >= stacks->pivots[j - 1]->pos)
			push(stacks->stack_b, stacks->stack_a, 'b');
		else if (node->pos >= stacks->pivots[i]->pos
			&& node->pos <= stacks->pivots[i + 1]->pos)
		{
			push(stacks->stack_b, stacks->stack_a, 'b');
			rotate(stacks->stack_b, 'b');
		}
		else
			rotate(stacks->stack_a, 'a');
		k--;
	}
}

void	side_median_pusher(t_stacks *stacks, t_node *node)
{
	int	k;

	k = stacks->stack_a->size;
	while (k > 0)
	{
		node = stacks->stack_a->start;
		if (node->pos <= stacks->pivots[0]->pos)
		{
			push(stacks->stack_b, stacks->stack_a, 'b');
			rotate(stacks->stack_b, 'b');
		}
		else
			push(stacks->stack_b, stacks->stack_a, 'b');
		k--;
	}
}

void	stack_median_sort(t_stack *stack_a, t_stack *stack_b, int median_count)
{
	t_stacks	*stacks;
	t_node		**pivots;
	t_node		*node;
	int			i;
	int			j;

	stacks = malloc(sizeof(t_stacks));
	pivots = malloc(sizeof(t_node) * (median_count - 1));
	if (!pivots || !stacks)
		return ;
	stacks->pivots = pivots;
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	get_median(stack_a, pivots, median_count);
	i = (median_count / 2) - 1;
	j = (median_count / 2) + 1;
	node = stacks->stack_a->start;
	while (i >= 0 && j <= median_count - 1)
		middle_median_pusher(stacks, node, i--, j++);
	side_median_pusher(stacks, node);
	free(pivots);
	free(stacks);
}
