/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:45:52 by norban            #+#    #+#             */
/*   Updated: 2024/07/07 18:16:08 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				i;
	int				diff;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && j < n)
	{
		j++;
		i++;
	}
	if (j == n)
		return (0);
	diff = s1[i] - s2[i];
	return (diff);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *str1 = "abcdewww";
	char *str2 = "alphafefefefe";
	int a = ft_strncmp(str1, str2, 5);
	int b = strncmp(str1, str2,5);
	printf("%d\n", a);
	printf("%d\n", b);
}*/
