/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:02:49 by norban            #+#    #+#             */
/*   Updated: 2024/07/08 17:39:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_updatestr(char *str, int i, int *ptr)
{
	if ((str[i] >= 32 && str[i] <= 47)
		|| (str[i] >= 58 && str[i] <= 64)
		|| (str[i] >= 91 && str[i] <= 96)
		|| (str[i] >= 123 && str[i] <= 127))
	{
		*ptr = 1;
	}
	else if (str[i] >= 97 && str[i] <= 122 && *ptr == 1)
	{
		str[i] -= 32;
		*ptr = 0;
	}
	else if (str[i] >= 61 && str[i] <= 90 && *ptr == 0)
	{
		str[i] += 32;
	}
	else
	{
		*ptr = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	*ptr;
	int	i;
	int	upafter;

	ptr = &upafter;
	i = 0;
	upafter = 1;
	while (str[i] != '\0')
	{
		ft_updatestr(str, i, ptr);
		i++;
	}
	return (str);
}
/*int main(void)
{
    char str[] = "j'ai -bieN";
    ft_strcapitalize(str);
}*/
