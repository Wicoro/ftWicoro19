/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:29:56 by norban            #+#    #+#             */
/*   Updated: 2024/07/07 14:34:35 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	int				j;
	unsigned int	k;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	k = 0;
	while (src[j] && k < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int main()
{
	char *ptr;
	char str1[6];
	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0';
	ptr = &str1[0];
	char *str2 = "def";

	ft_strncat(ptr, str2, 2);
	printf("%s\n", str1);
}*/
