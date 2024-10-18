/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:49:04 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 10:28:45 by norban           ###   ########.fr       */
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
		return (0);
	str = 0;
	return (1);
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
} */
