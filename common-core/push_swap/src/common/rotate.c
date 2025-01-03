/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:57:08 by norban            #+#    #+#             */
/*   Updated: 2025/01/03 16:04:19 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	The 1st element of the stack become the last
*/
void	rotate(t_stack *stack, char c)
{
	t_node	*rotated;

	if (stack->size <= 1)
		return ;
	rotated = stack->start;
	stack->start = rotated->next;
	stack->start->prev = NULL;
	stack->end->next = rotated;
	rotated->prev = stack->end;
	stack->end = rotated;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rotate_double(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	ft_putstr_fd("rr\n", 1);
}

void	numbered_rotate(t_stack *s_a, t_stack *s_b, int count, t_node *node)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (s_b->start->pos == node->pos - 1)
			push(s_a, s_b, 'a');
		else
			rotate(s_b, 'b');
		i++;
	}
}
