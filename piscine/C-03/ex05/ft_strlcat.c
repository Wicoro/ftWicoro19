/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:23:18 by norban            #+#    #+#             */
/*   Updated: 2024/07/10 10:12:45 by norban           ###   ########.fr       */
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
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	j = dest_len;
	src_len = ft_strlen(src);
	if (size == 0 || size <= dest_len)
		return (src_len + size);
	while (src[i] && i < size - dest_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (src_len + dest_len);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char* src = "wxyz";
	char* ptr;
	char* ptr2;
	char dest[24] = "abcdefghijklmonpqrstuv";
	char dest2[24] = "abcdefghijklmonpqrstuv";
	ptr = &dest[0];
	ptr2 = &dest2[0];
	int a = ft_strlcat(ptr, src, 24);
	printf("%s\n", ptr);
	int b = strlcat(ptr2, src, 24);
	printf("%s\n", ptr);
	printf("%d\n", a);
	printf("%d\n", b);
}*/
