/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:57:50 by norban            #+#    #+#             */
/*   Updated: 2024/07/05 10:11:52 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		if (!(97 <= c && c <= 122))
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

	int a = ft_str_is_lowercase(str);
	int b = ft_str_is_lowercase(str2);
	int c = ft_str_is_lowercase(str3);
	int d = ft_str_is_lowercase(str4);
	if (a == 1 && b == 0 && c == 0 && d == 1)
	{
		write(1, "W\0", 2);
	}
}*/
