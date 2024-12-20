/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:18:12 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 17:44:01 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checkSort(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *node;
    
    if (stack_b->size != 0)
        return (0);
    node = stack_a->start;
    while (node != stack_a->end)
    {
        if (node->value > node->next->value)
            return (0);
        node = node->next;
    }
    return (1);
}
