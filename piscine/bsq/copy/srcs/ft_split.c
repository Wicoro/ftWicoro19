/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:00:14 by mokariou          #+#    #+#             */
/*   Updated: 2024/07/22 21:00:23 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_da_sep(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cat_da_strr(char *src, int star, int end)
{
	int		i;
	int		len;
	char	*tab;

	len = end - star;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		tab[i] = src[star + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		start;
	char	**tab;

	i = 0;
	j = 0;
	start = 0;
	tab = malloc(sizeof(char *) * (len(str) + 1));
	while (str[i])
	{
		while (str[i] && find_da_sep(&str[i]))
			i++;
		start = i;
		while (str[i] && !find_da_sep(&str[i]))
			i++;
		if (i > start)
		{
			tab[j] = cat_da_strr(str, start, i);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
