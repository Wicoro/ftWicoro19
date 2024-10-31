/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:52:58 by norban            #+#    #+#             */
/*   Updated: 2024/07/18 23:02:32 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
/*
int r1(char *str)
{
	str = 0;
	return (0);
}
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char **str = malloc(3 * sizeof(char *));
	str[0] = "ab";
	str[1] = "B";
	str[2] = "Cf";
	printf("%d\n", ft_count_if(str, 3, &r1));
}*/
