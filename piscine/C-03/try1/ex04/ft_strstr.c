/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:39:11 by norban            #+#    #+#             */
/*   Updated: 2024/07/07 15:18:18 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_same(char *str, char *to_find, int i, int j)
{
	while (str[i] == to_find[j] && to_find[j])
	{
		i++;
		j++;
	}
	if (to_find[j])
		return (0);
	else
		return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		finder;
	char	*ptr;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	finder = 0;
	while (str[i] && finder != 1)
	{
		if (str[i] == to_find[0])
			finder = ft_is_same(str, to_find, i, 0);
		i++;
	}
	if (finder == 1)
	{
		ptr = &str[i - 1];
		return (ptr);
	}
	else
		return (0);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char *str1 = "abcdefghij";
	char *str2 = "def";
	char *ptr1 = ft_strstr(str1, str2);
	char *ptr2 = strstr(str1, str2);
	printf("%p\n", ptr1);
	printf("%p\n", ptr2);
}*/
