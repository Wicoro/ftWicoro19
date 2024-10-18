/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:54:11 by norban            #+#    #+#             */
/*   Updated: 2024/07/07 11:38:19 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	ft_dectohex(int a)
{
	unsigned char	c;

	if (a < 10)
		a += 48;
	else
		a += 87;
	c = a;
	return (c);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	int				j;
	unsigned char	hex1;
	unsigned char	hex2;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			j = str[i];
			hex1 = ft_dectohex(j / 16);
			hex2 = ft_dectohex(j % 16);
			write(1, &hex1, 1);
			write(1, &hex2, 1);
		}
		i++;
	}
}
/*int main(void)
{
    char tab[] = "Voici un \nTest";
    //char    *ptr = &tab[0];

    ft_putstr_non_printable(tab);
}*/
