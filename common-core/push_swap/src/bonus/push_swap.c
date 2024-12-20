/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:27:00 by norban            #+#    #+#             */
/*   Updated: 2024/12/20 18:03:16 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(char *str)
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

int	checkvalidparams(int ac, char **av)
{
	int		i;
	char	**input;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		i = 0;
		while (input[i])
		{
			if (isnumber(input[i]) == 0)
				return (0);
			i++;
		}
	}
	i = 1;
	while (i < ac)
	{
		if (isnumber(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (checkvalidparams(ac, av) == 0)
	{
		ft_putstr_fd("Error", 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_b->size = 0;
	create_stack(stack_a, ac - 1, av);
	if (ac <= 6)
		smallstacksort(stack_a, stack_b);
	else
		stack_sort(stack_a, stack_b);
	printchecksort(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
