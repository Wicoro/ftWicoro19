/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:57:08 by norban            #+#    #+#             */
/*   Updated: 2025/01/09 18:21:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	The last element of the stack become the first
*/
void	reverse_rotate(t_stack *stack, char c)
{
	t_node	*rotated;

	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
		swap(stack, c);
	rotated = stack->end;
	stack->end = rotated->prev;
	stack->end->next = NULL;
	stack->start->prev = rotated;
	rotated->next = stack->start;
	stack->start = rotated;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_double(t_stack *stack_a, t_stack *stack_b, char c)
{
	reverse_rotate(stack_a, 'c');
	reverse_rotate(stack_b, 'c');
	if (c == 'r')
		ft_putstr_fd("rrr\n", 1);
}

void	numbered_rrotate(t_stack *s_a, t_stack *s_b, int count, t_node *node)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		if (s_b->end->pos == node->pos - 1)
		{
			reverse_rotate(s_b, 'b');
			push(s_a, s_b, 'a');
		}
		else
			reverse_rotate(s_b, 'b');
		i++;
	}
}
