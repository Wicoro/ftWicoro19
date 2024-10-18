/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:53:06 by norban            #+#    #+#             */
/*   Updated: 2024/07/05 09:56:25 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		if (!((48 <= c && c <= 57)))
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
	char* str = "123456";
	char* str3 = "jbvuhHUBVYGU564654";
	char* str4 = "";

	int a = ft_str_is_numeric(str);
	int c = ft_str_is_numeric(str3);
	int d = ft_str_is_numeric(str4);
	if (a == 1 && c == 0 && d == 1)
	{
		write(1, "W\0", 2);
	}
}*/
