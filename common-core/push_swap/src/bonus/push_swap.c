/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:27:00 by norban            #+#    #+#             */
/*   Updated: 2025/01/03 17:13:10 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' && str[1])
		i++;
	if (atoi_too_big(str) == 1)
		return (0);
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	splitparams(char *av)
{
	int		i;
	char	**input;

	input = ft_split(av, ' ');
	i = 0;
	if (!(input[0]))
		return (0);
	while (input[i])
	{
		if (isnumber(input[i]) == 0)
			return (0);
		i++;
	}
	free_split(input);
	return (1);
}

int	checkvalidparams(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (0);
	else if (ac == 2 && splitparams(av[1]) == 0)
		return (0);
	else if (ac != 2)
	{
		i = 1;
		while (i < ac)
		{
			if (isnumber(av[i]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (checkvalidparams(ac, av) == 0)
		return (printerror(), 0);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (2);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (free_stack(stack_a), 2);
	stack_b->size = 0;
	create_stack(stack_a, ac - 1, av);
	if (checkvalidstack(stack_a) == 0)
		return (free_stack(stack_a), free_stack(stack_b), printerror(), 0);
	if (stack_a->size < 6 && checksort(stack_a, stack_b) == 0)
		smallstacksort(stack_a, stack_b);
	else if (checksort(stack_a, stack_b) == 0)
		stack_sort(stack_a, stack_b);
	printchecksort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
