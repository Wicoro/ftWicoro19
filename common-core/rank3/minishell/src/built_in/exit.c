/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:40:06 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/13 19:57:48 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_numeric_arg(t_datashell *data, char **cmd_tab)
{
	int	i;

	(void) data;
	i = 0;
	if (cmd_tab[1][i] == '-' || cmd_tab[1][i] == '+')
		i++;
	while (cmd_tab[1][i])
	{
		if (!ft_isdigit(cmd_tab[1][i]))
		{
			ft_putstr_fd("exit\nmaxi-total: exit : ", 2);
			ft_putstr_fd(cmd_tab[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			data->end_flag = 2;
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_arg_count(char **cmd_tab, t_datashell *data)
{
	int	i;

	i = 0;
	while (cmd_tab[i])
	{
		if (i == 2)
		{
			ft_putstr_fd("exit\nexit : too many arguments\n", 2);
			data->return_val = 1;
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	overflow_error(char *str, t_datashell *data)
{
	ft_putstr_fd("exit\nmaxi-total: exit : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	data->end_flag = 2;
	return (0);
}

static long long	ft_atoll(char *str, t_datashell *data)
{
	int			sign;
	int			digit;
	long long	result;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (sign == 1 && (result > (LLONG_MAX - digit) / 10))
			return (overflow_error(str, data));
		if (sign == -1 && (-result < (LLONG_MIN + digit) / 10))
			return (overflow_error(str, data));
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}

int	bi_exit(t_datashell *data, char **cmd_tab)
{
	int		n;

	if (!cmd_tab)
		return (data->end_flag = 0);
	if (!cmd_tab[1])
	{
		data->end_flag = 0;
		n = data->return_val;
		ft_putstr_fd("exit\n", 2);
		return (n);
	}
	if (check_numeric_arg(data, cmd_tab) == -1)
		return (-1);
	if (check_arg_count(cmd_tab, data) == -1)
		return (-1);
	n = ft_atoll(cmd_tab[1], data);
	n = value_fix(n);
	ft_putstr_fd("exit\n", 2);
	data->end_flag = n;
	return (0);
}
