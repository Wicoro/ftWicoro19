/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallstacksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:57:43 by norban            #+#    #+#             */
/*   Updated: 2024/12/31 14:39:35 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallstacksort5(t_stack *stack_a, t_stack *stack_b)
{
	while (checksort(stack_a, stack_b) == 0 && stack_a->size != 3)
	{
		while (stack_a->start->pos == 0 || stack_a->start->pos == 1)
			push(stack_b, stack_a, 'b');
		if (stack_a->size != 3
			&& (stack_a->start->pos != 0 || stack_a->start->pos != 1))
			rotate(stack_a, 'a');
	}
	if (stack_a->size == 3)
	{
		if (stack_a->end->pos != 4 && stack_a->end->prev->pos == 4)
			reverse_rotate(stack_a, 'a');
		else if (stack_a->end->pos != 4)
			rotate(stack_a, 'a');
		if (checksort(stack_a, NULL) == 0)
			swap(stack_a, 'a');
	}
	if (stack_b->start->pos < stack_b->start->next->pos)
		swap(stack_b, 'b');
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
}

void	smallstacksort4(t_stack *stack_a, t_stack *stack_b)
{
	while (checksort(stack_a, stack_b) == 0 && stack_a->size != 2)
	{
		while (stack_a->start->pos == 0 || stack_a->start->pos == 1)
			push(stack_b, stack_a, 'b');
		if (stack_a->size != 2
			&& (stack_a->start->pos != 0 || stack_a->start->pos != 1))
			rotate(stack_a, 'a');
	}
	while (checksort(stack_a, stack_b) == 0)
	{
		if (stack_a->start->pos > stack_a->start->next->pos)
			swap(stack_a, 'a');
		if (stack_b->start->pos < stack_b->start->next->pos)
			swap(stack_b, 'b');
		push(stack_a, stack_b, 'a');
		push(stack_a, stack_b, 'a');
	}
}

void	smallstacksort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (checksort(stack_a, stack_b) == 0)
			swap(stack_a, 'a');
		return ;
	}
	else if (stack_a->size == 3)
	{
		if (stack_a->end->pos != 2 && stack_a->end->prev->pos == 2)
			reverse_rotate(stack_a, 'a');
		else if (stack_a->end->pos != 2)
			rotate(stack_a, 'a');
		if (checksort(stack_a, stack_b) == 0)
			swap(stack_a, 'a');
	}
	else if (stack_a->size == 4)
		smallstacksort4(stack_a, stack_b);
	else if (stack_a->size == 5)
		smallstacksort5(stack_a, stack_b);
}
