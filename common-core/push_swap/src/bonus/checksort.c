/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:58:11 by norban            #+#    #+#             */
/*   Updated: 2025/01/09 18:27:31 by norban           ###   ########.fr       */
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

int	make_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strlen(line) == 3 && ft_strncmp(line, "ra", 2) == 0)
		return (rotate(stack_a, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "rb", 2) == 0)
		return (rotate(stack_b, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "rr", 2) == 0)
		return (rotate_double(stack_b, stack_a, 'c'), 1);
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rra", 3) == 0)
		return (reverse_rotate(stack_a, 'c'), 1);
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rrb", 3) == 0)
		return (reverse_rotate(stack_a, 'c'), 1);
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rrr", 3) == 0)
		return (reverse_rotate_double(stack_b, stack_a, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "sa", 2) == 0)
		return (swap(stack_a, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "sb", 2) == 0)
		return (swap(stack_b, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "ss", 2) == 0)
		return (swap_double(stack_b, stack_a, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "pa", 2) == 0)
		return (push(stack_a, stack_b, 'c'), 1);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "pb", 2) == 0)
		return (push(stack_b, stack_a, 'c'), 1);
	return (0);
}

int	read_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || line[0] == '\n')
			break ;
		if (make_operation(line, stack_a, stack_b) == 0)
			return (free(line), printerror(), 1);
		free(line);
	}
	return (0);
}
