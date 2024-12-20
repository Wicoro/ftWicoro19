/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:58:11 by norban            #+#    #+#             */
/*   Updated: 2024/12/20 19:14:17 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b)
	{
		if (stack_b->size != 0)
			return (0);
	}
	node = stack_a->start;
	while (node != stack_a->end)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	printerror(void)
{
	ft_putstr_fd("Error", 2);
	ft_putchar_fd('\n', 2);
}
