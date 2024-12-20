/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:10:09 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 15:16:28 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(t_node *previous, char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->prev = previous;
	node->value = ft_atoi(value);
	return (node);
}

t_node	*create_list(char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->prev = NULL;
	node->value = ft_atoi(value);
	return (node);
}

void	get_stack_pos(int tab[], t_stack *stack)
{
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	node = stack->start;
	while (i < stack->size)
	{
		j = 0;
		while (tab[j] != node->value)
			j++;
		node->pos = j;
		i++;
		node = node->next;
	}
}

void	tab_quicksort(t_stack *stack)
{
	int		*tab;
	t_node	*node;
	int		i;

	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		return ;
	node = stack->start;
	i = 0;
	while (i < stack->size)
	{
		tab[i] = node->value;
		node = node->next;
		i++;
	}
	quicksort(&tab[0], 0, stack->size - 1);
	get_stack_pos(tab, stack);
	free(tab);
}

void	create_stack(t_stack *stack, int size, char **av)
{
	int		i;
	t_node	*node;

	i = 1;
	node = create_list(av[i++]);
	stack->start = node;
	while (i <= size)
	{
		if (av)
			node->next = new_node(node, av[i]);
		node = node->next;
		i++;
	}
	stack->end = node;
	stack->size = size;
	tab_quicksort(stack);
}
