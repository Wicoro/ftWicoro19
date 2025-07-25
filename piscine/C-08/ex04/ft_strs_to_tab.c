/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:25:41 by norban            #+#    #+#             */
/*   Updated: 2024/07/18 14:58:23 by norban           ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strs;
	int			i;

	strs = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strs[i].size = ft_strlen(av[i]);
		strs[i].str = av[i];
		strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs[i].str = 0;
	strs[i].size = 0;
	strs[i].copy = 0;
	return (strs);
}
/*#include <stdio.h>
int main(int ac, char **av)
{
	t_stock_str *strs;
	strs = ft_strs_to_tab(ac, av);
	int i = 0;
	while(strs[i].size)
	{
		printf("%d | %s | %s\n", strs[i].size, strs[i].str, strs[i].copy);
		i++;
	}
}*/
