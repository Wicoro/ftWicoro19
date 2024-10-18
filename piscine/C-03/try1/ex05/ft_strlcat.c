/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:23:18 by norban            #+#    #+#             */
/*   Updated: 2024/07/07 18:17:10 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;
	unsigned int	returned;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	returned = i;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	returned += ft_strlen(src);
	dest[i] = '\0';
	return (returned);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char* src = "defgh";
	char* ptr;
	char dest[9];
	dest[0] = 'a';
	dest[1] = 'b';
	dest[2] = 'c';
	dest[3] = '\0';
	ptr = &dest[0];
	ft_strlcat(ptr, src, 9);
	strlcat(ptr, src, 9);
	printf("%s", ptr);
}*/
