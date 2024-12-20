/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:04:10 by norban            #+#    #+#             */
/*   Updated: 2024/12/20 19:12:57 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "libft.h"
# include "unistd.h"
# include "fcntl.h"
# include "stdio.h"

typedef struct s_node
{
	int				value;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*start;
	struct s_node	*end;
}	t_stack;

typedef struct s_stacks_pivots
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	**pivots;
}	t_stacks;

void	create_stack(t_stack *stack, int size, char **value);
void	stack_sort(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack, char c);
void	swap_double(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack_a, t_stack *stack_b, char c);
void	rotate(t_stack *stack, char c);
void	numbered_rotate(t_stack *s_a, t_stack *s_b, int count, t_node *node);
void	rotate_double(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack, char c);
void	numbered_rrotate(t_stack *s_a, t_stack *s_b, int count, t_node *node);
void	reverse_rotate_double(t_stack *stack_a, t_stack *stack_b);
void	quicksort(int arr[], int low, int high);
void	get_median(t_stack *stack, t_node **pivots, int count);
void	stack_median_sort(t_stack *stack_a, t_stack *stack_b, int median_count);
int		checksort(t_stack *stack_a, t_stack *stack_b);
void	printchecksort(t_stack *stack_a, t_stack *stack_b);
void	smallstacksort(t_stack *stack_a, t_stack *stack_b);
void	printerror(void);

#endif
