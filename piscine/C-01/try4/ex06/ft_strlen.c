/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:26:13 by norban            #+#    #+#             */
/*   Updated: 2024/07/04 11:25:45 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (*str)
	{
		a++;
		str++;
	}
	return (a);
}
/*int main(void)
{
	char* str;
	int length;

	str = "alpha";
	length = ft_strlen(str);
	if (length == 5)
	{
		write(1, "W\n", 2);
	}
}*/
