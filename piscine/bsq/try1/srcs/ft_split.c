/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:00:14 by mokariou          #+#    #+#             */
/*   Updated: 2024/07/24 21:05:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_next_string(char *str, int *j)
{
	char	*substr;
	int		length;
	int		i;

	length = 0;
	while (str[*j + length] != '\n')
		length++;
	substr = malloc(sizeof(char) * (length + 1));
	if (!substr)
		return (0);
	i = 0;
	while (str[*j] != '\n')
	{
		substr[i] = str[*j];
		*j += 1;
		i++;
	}
	substr[i] = '\0';
	*j += 1;
	return (substr);
}

int	ft_get_tab_size(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (str[i - 1] != '\n')
		return (0);
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		tab_size;
	char	**tab;

	i = 0;
	j = 0;
	tab_size = ft_get_tab_size(str);
	if (tab_size < 2)
		return (0);
	tab = malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (0);
	while (i < tab_size)
	{
		tab[i] = ft_get_next_string(str, &j);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
/*
#include <stdio.h>
int	main()
{
	char *str = "je\nsuis\nnicolas";
	char **split =  ft_split(str);
	if (split == 0)
	{
		printf("map error");
		return (0);
	}
	int i = 0;
	while (split[i])
		printf("%s\n", split[i++]);
	return (0);
}*/
