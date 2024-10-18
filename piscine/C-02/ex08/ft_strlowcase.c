/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:14:02 by norban            #+#    #+#             */
/*   Updated: 2024/07/06 16:30:17 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		if (65 <= c && c <= 90)
		{
			str[i] += 32;
		}
		i++;
		c = str[i];
	}
	return (str);
}
/*int main(void)
{
	char str[] = {'a', 'b', 'c', 'A', 'B', 'C', '1', '2', '3'};

	ft_strlowcase(str);
	if (str[1] == 'b' && str[6] == '1' && str[3] == 'a')
	{
		write(1, "W\0", 2);
	}
}*/
