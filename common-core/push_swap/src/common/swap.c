/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:39 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 15:19:08 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap the 1st and 2nd value of the stack
*/
void	swap(t_stack *stack, char c)
{
	int	tmp;
	int	tmp2;

	if (stack->size < 2)
		return ;
	tmp = stack->start->value;
	stack->start->value = stack->start->next->value;
	stack->start->next->value = tmp;
	tmp2 = stack->start->pos;
	stack->start->pos = stack->start->next->pos;
	stack->start->next->pos = tmp2;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

/*
	Swap the 2 first value of stack A and B
*/
void	swap_double(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 'c');
	swap(stack_b, 'c');
	ft_putstr_fd("ss\n", 1);
}
