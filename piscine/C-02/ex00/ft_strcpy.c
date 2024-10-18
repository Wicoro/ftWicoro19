/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:43:10 by norban            #+#    #+#             */
/*   Updated: 2024/07/08 11:01:56 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
		index++;
	}
	*dest = *src;
	dest -= index;
	return (dest);
}
int main(void)
{
	char* a = "alpha";
	char c[6];

	ft_strcpy(c, a);

	int i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
 }
/*
char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
} */
