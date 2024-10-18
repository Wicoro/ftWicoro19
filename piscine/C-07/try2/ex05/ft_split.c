/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:48:14 by norban            #+#    #+#             */
/*   Updated: 2024/07/15 15:17:46 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_char_sep(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_string(char *str, char *charset, int j)
{
	char	*s1;
	int		k;
	int		i;

	k = 0;
	while (str[j + k] && is_char_sep(str[j + k], charset) == 0)
		k++;
	s1 = malloc(sizeof(char) * (k + 1));
	i = 0;
	while (i < k)
	{
		s1[i] = str[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

int get_strc(char *str, char *charset)
{
	int	i;
	int	strc;

	i = 0;
	strc = 0;
	while (str[i])
	{
		while (str[i] && is_char_sep(str[i], charset) > 0)
			i++;
		while (str[i] && is_char_sep(str[i], charset) == 0)
			i++;
		strc++;
		if (!str[i] && is_char_sep(str[i - 1], charset) > 0)
			strc--;
	}
	if (is_char_sep(str[0], charset) > 0)
		strc--;
	if (is_char_sep(str[0], charset) > 0 && is_char_sep(str[0], charset) > 0)
		strc++;
	return (strc);
}

char	**ft_split(char *str, char *charset)
{
	int		strc;
	int		i;
	int		j;
	char	**tab;

	strc = get_strc(str, charset);
	tab = malloc(sizeof(char *) * (strc + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (is_char_sep(str[j], charset) > 0)
		j++;
	while (i < strc)
	{
		tab[i] = get_next_string(str, charset, j);
		j += ft_strlen(&tab[i][0]);
		i++;
		while (str[j] && is_char_sep(str[j], charset) > 0)
			j++;
	}
	tab[i] = 0;
	return (tab);
}
/*int main()
{
	char *str = "55/";
	char *sep = "/";
	char **tab = ft_split(str, sep);

	int i = 0;
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
