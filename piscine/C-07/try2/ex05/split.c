/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:17:59 by norban            #+#    #+#             */
/*   Updated: 2024/07/12 20:23:05 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strstr(char *str, char *sep, int i)
{
	int	j;

	while (str[i])
	{
		if (str[i] == sep[0])
		{
			j = 0;
			while (sep[j] == str[i + j] && sep[j])
			{
				j++;
			}
			if (!sep[j])
				return (i);
		}
		i++;
	}
	return (i);
}

char *ft_get_string(char *str, int i, char *charset)
{
	int	next_sep;
	char *s1;
	int len;
	int j;

	next_sep = ft_strstr(str, charset, i + 1);
	len = next_sep - i;
	s1 = (char *) malloc(sizeof(char) * len);
	j = 0;
	while (j < len && str[i])
	{
		s1[j] = str[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);	
}

char **ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int 	strc;
	char 	**tab;

	strc = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_strstr(str, charset, i) != 0)
		{
			strc++;
			i = ft_strstr(str, charset, i + 1);
		}
	}
	tab = (char **) malloc(sizeof(char*) * (strc + 1));
	j = 0;
	i = 0;
	while (j < strc)
	{
		tab[j] = ft_get_string(str, i, charset);
		j++;
		i = i + ft_strlen(tab[j - 1]) + ft_strlen(charset);
	}
	tab[j] = 0;
	return (tab);
}
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	char	**tab = ft_split(av[1], av[2]);
	int i = 0;
	while (tab[i])
	{
		int j = 0;
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
