/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:01:03 by norban            #+#    #+#             */
/*   Updated: 2024/07/16 18:26:41 by norban           ###   ########.fr       */
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

int	ft_getsize(int size, char **strs)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

void	ft_fill_array(int size, char *str, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[len] = strs[i][j];
			len++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			str[len] = sep[j];
			len++;
			j++;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	len = ft_getsize(size, strs);
	len += (size - 1) * ft_strlen(sep);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_fill_array(size, str, strs, sep);
	str[ft_strlen(str)] = '\0';
	return (str);
}
/*#include <stdio.h>
int main()
{
	char *tab[] = {};
	char *sep = "abc";
	char *strf = ft_strjoin(0, tab, sep);

	printf("%s\n", strf);
}*/
