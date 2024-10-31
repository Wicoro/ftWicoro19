/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:00:16 by norban            #+#    #+#             */
/*   Updated: 2024/07/05 10:02:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		if (!((65 <= c && c <= 90)))
		{
			return (0);
		}
		i++;
		c = str[i];
	}
	return (1);
}
/*int main(void)
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char* str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* str3 = "jbvuhHUBVYGU564654";
	char* str4 = "";

	int a = ft_str_is_uppercase(str);
	int b = ft_str_is_uppercase(str2);
	int c = ft_str_is_uppercase(str3);
	int d = ft_str_is_uppercase(str4);
	if (a == 0 && b == 1 && c == 0 && d == 1)
	{
		write(1, "W\0", 2);
	}
}*/
