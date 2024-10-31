/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:23:50 by norban            #+#    #+#             */
/*   Updated: 2024/07/18 23:52:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	check_case(char *op, int b)
{
	if (!(op[0] == '+' || op[0] == '-' || op[0] == '/'
			|| op[0] == 42 || op[0] == '%'))
	{
		write(1, "0", 1);
		return (0);
	}
	if (op[0] == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return (0);
	}
	if (op[0] == '/' && b == 0)
	{
		write(1, "Stop : division by zero", 23);
		return (0);
	}
	return (1);
}

void	do_op(char *val1, char *val2, char *op)
{
	int	a;
	int	b;

	a = ft_atoi(val1);
	b = ft_atoi(val2);
	if (check_case(op, b) != 0)
	{
		if (op[0] == '+')
			ft_putnbr(a + b);
		if (op[0] == '-')
			ft_putnbr(a - b);
		if (op[0] == '/')
			ft_putnbr(a / b);
		if (op[0] == '*')
			ft_putnbr(a * b);
		if (op[0] == '%')
			ft_putnbr(a % b);
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(av[1], av[3], av[2]);
	return (0);
}
