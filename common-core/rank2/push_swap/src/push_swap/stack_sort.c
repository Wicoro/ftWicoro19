/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:48 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 15:16:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_best_rotation(t_stack *stack, t_stack *stack_a, t_node *node)
{
	t_node	*s;
	t_node	*e;
	int		s_count;
	int		e_count;

	s = stack->start;
	e = stack->end;
	s_count = 0;
	e_count = 0;
	while (s->pos != node->pos)
	{
		s = s->next;
		s_count += 1;
	}
	while (e->pos != node->pos)
	{
		e = e->prev;
		e_count += 1;
	}
	if (e_count < s_count)
		numbered_rrotate(stack_a, stack, e_count, node);
	else
		numbered_rotate(stack_a, stack, s_count, node);
}

void	locate_pos(int pos, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;

	i = stack_b->size;
	node = stack_b->start;
	while (i > 0)
	{
		if (node->pos == pos)
		{
			get_best_rotation(stack_b, stack_a, node);
			return ;
		}
		node = node->next;
		i--;
	}
}

void	sort_part(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	pos = stack_b->size - 1;
	while (pos >= 0)
	{
		locate_pos(pos, stack_a, stack_b);
		push(stack_a, stack_b, 'a');
		if (stack_a->start->next
			&& stack_a->start->pos > stack_a->start->next->pos)
		{
			swap(stack_a, 'a');
			pos -= 2;
		}
		else
			pos--;
	}
}

int	sqrt_rounded(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	while (i * i != nb && nb / i >= i)
		i++;
	return (i);
}

void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	median_count;

	median_count = sqrt_rounded(stack_a->size) / 2 + 4;
	if (median_count % 2 == 0)
		median_count++;
	stack_median_sort(stack_a, stack_b, median_count);
	sort_part(stack_a, stack_b);
}
