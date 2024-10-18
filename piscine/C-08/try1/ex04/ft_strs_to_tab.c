/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:25:41 by norban            #+#    #+#             */
/*   Updated: 2024/07/16 15:28:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include "stdlib.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strs;
	struct s_stock_str	str;
	int					i;

	strs = malloc(sizeof(struct s_stock_str) * (ac));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		str.size = ft_strlen(av[i]);
		str.str = av[i];
		str.copy = av[i];
		strs[i] = str;
		i++;
	}
	return (strs);
}
/*#include <stdio.h>
int main(int ac, char **av)
{
	struct s_stock_str *strs;
	strs = ft_strs_to_tab(ac, av);
	int i = 0;
	while(strs[i].size)
	{
		printf("%d | %s | %s\n", strs[i].size, strs[i].str, strs[i].copy);
		i++;
	}
}*/
