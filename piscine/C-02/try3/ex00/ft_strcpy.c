/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:43:10 by norban            #+#    #+#             */
/*   Updated: 2024/07/05 10:51:45 by norban           ###   ########.fr       */
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
/*int main(void)
{
	char* a = "alpha";
	char* b;
	char c[6];

	b = &c[0];
	ft_strcpy(b, a);

	while(*b)
	{
		write(1, b, 1);
		b++;
	}
 } */
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
