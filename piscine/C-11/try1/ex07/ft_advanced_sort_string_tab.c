/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:29:59 by norban            #+#    #+#             */
/*   Updated: 2024/07/19 10:09:25 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (tab[j + 1] && cmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap(&tab[j], &tab[j + 1]);
				i = 0;
			}
			j++;
		}
		i++;
	}
}
/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char **tab;

	tab = malloc(sizeof(char *) * 4);
	tab[3] = 0;
	tab[0] = "zzz";
	tab[1] = "aaa";
	tab[2] = "mmm";
	int i = 0;
	ft_sort_string_tab(tab, &ft_strcmp);
	while (i < 4)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
