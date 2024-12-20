/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:02:14 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 15:19:59 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_size1_origin(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pushed;

	pushed = stack_b->start;
	stack_b->start = NULL;
	stack_b->end = NULL;
	stack_a->start->prev = pushed;
	pushed->next = stack_a->start;
	stack_a->start = pushed;
}

void	push_empty_dest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pushed;

	pushed = stack_b->start;
	stack_a->start = pushed;
	stack_a->end = pushed;
	stack_b->start = pushed->next;
	stack_b->start->prev = NULL;
	pushed->next = NULL;
	pushed->prev = NULL;
}

/*
   Take the 1st element from B and put it in the top of A
*/
void	push(t_stack *stack_a, t_stack *stack_b, char c)
{
	t_node	*pushed;

	if (stack_b->size < 1)
		return ;
	else if (stack_b->size == 1)
		push_size1_origin(stack_a, stack_b);
	else if (stack_a->size == 0)
		push_empty_dest(stack_a, stack_b);
	else
	{
		pushed = stack_b->start;
		stack_b->start = pushed->next;
		stack_b->start->prev = NULL;
		stack_a->start->prev = pushed;
		pushed->next = stack_a->start;
		stack_a->start = pushed;
	}
	stack_b->size -= 1;
	stack_a->size += 1;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}
