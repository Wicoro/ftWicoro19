/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:39:07 by norban            #+#    #+#             */
/*   Updated: 2025/05/05 12:04:41 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_nl(char	**split_echo)
{
	int	i;
	int	j;

	i = 1;
	while (split_echo[i])
	{
		if (split_echo[i][0] != '-')
			return (i);
		else if (!split_echo[i][1])
			return (i);
		j = 1;
		while (split_echo[i][j])
		{
			while (split_echo[i][j] == 'n')
				j++;
			if (split_echo[i][j])
				return (i);
		}
		i++;
	}
	return (i);
}

int	bi_echo(char **split_echo)
{
	int		i;
	int		nl;

	i = is_nl(split_echo);
	nl = 1;
	if (i > 1)
		nl = 0;
	while (split_echo[i])
	{
		printf("%s", split_echo[i]);
		if (split_echo[i + 1])
			printf(" ");
		i++;
	}
	if (nl == 1)
		printf("\n");
	return (0);
}
