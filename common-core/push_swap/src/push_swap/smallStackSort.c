/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallStackSort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:36:16 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 17:57:09 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    smallStackSort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 3)
    {
        while (checkSort(stack_a, stack_b) == 0)
        {
            if (stack_a->start < stack_a->start->next
                && stack_a->start->next > stack_a->start->next->next)
                swap(stack_a, 'a');
            rotate(stack_a, 'a');
        }
        return ;
    }
}