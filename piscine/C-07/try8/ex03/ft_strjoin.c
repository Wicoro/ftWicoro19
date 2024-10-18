/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:01:03 by norban            #+#    #+#             */
/*   Updated: 2024/07/18 09:45:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_getsize(int size, char **strs, char *sep)
{
	int	i;
	int	sep_size;
	int	len;

	i = 0;
	sep_size = ft_strlen(sep);
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += sep_size * (size - 1);
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	len = ft_getsize(size, strs, sep);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	str[0] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int main()
{
	char *tab[] = {"lol", "pouic" , "", "youpiiii"};
	char *sep = "1234";
	char *strf = ft_strjoin(4, tab, sep);

	printf("%s\n", strf);
}*/
