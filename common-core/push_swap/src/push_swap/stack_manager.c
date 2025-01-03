/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:39:29 by norban            #+#    #+#             */
/*   Updated: 2025/01/03 16:58:04 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublenb(t_node *node, t_stack *stack_a)
{
	int	*tab;
	int	zero;
	int	i;

	zero = 0;
	tab = malloc(sizeof(int) * stack_a->size);
	if (!tab)
		return (0);
	ft_bzero(tab, sizeof(int) * stack_a->size);
	while (node)
	{
		i = 0;
		if (node->value == 0)
			zero++;
		while (tab[i] != 0)
		{
			if ((node->value != 0 && node->value == tab[i]))
				return (free(tab), 0);
			i++;
		}
		tab[i] = node->value;
		node = node->next;
	}
	return (free(tab), zero <= 1);
}

int	checkvalidstack(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->start;
	return (check_doublenb(node, stack_a));
}

void	free_stack(t_stack *stack)
{
	t_node	*node1;
	int		i;

	node1 = stack->start;
	if (node1)
	{
		i = stack->size;
		while (i-- > 1 && node1 && node1->next)
		{
			node1 = node1->next;
			free(node1->prev);
			node1->prev = NULL;
		}
	}
	free(node1);
	free(stack);
	stack = NULL;
}
