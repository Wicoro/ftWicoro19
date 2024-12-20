/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printCheckSort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:18:12 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 16:51:59 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    printCheckSort(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    
    i = checkSort(stack_a, stack_b);
    if (i = 0)
        ft_putstr_fd("KO", 1);
    else
        ft_putstr_fd("OK", 1);
}