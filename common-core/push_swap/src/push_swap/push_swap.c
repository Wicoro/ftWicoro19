/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:27:00 by norban            #+#    #+#             */
/*   Updated: 2024/12/18 16:42:50 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isNumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checkValidParams(int ac, char **av)
{
	int	i;
	
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (isNumber(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (checkValidParams(ac, av) == 0)
	{
		ft_putstr_fd("Error", 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_b->size = 0;
	create_stack(stack_a, ac - 1, av);
	if (ac <= 6)
		smallStackSort(stack_a, stack_b);
	else
		stack_sort(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
