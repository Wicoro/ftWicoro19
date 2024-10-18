/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:49:04 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 10:44:45 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getlength(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	count;
	int	length;

	i = 0;
	count = 0;
	length = ft_getlength(tab);
	while (i < length)
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

/*
int r1(char *str)
{
	if (str[0] == 'a')
		return (1);
	str = 0;
	return (0);
}
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char **str = malloc(3 * sizeof(char *));
	str[0] = "ab";
	str[1] = "aB";
	str[2] = "aCf";
	printf("%d\n", ft_count_if(str, &r1));
} 
*/