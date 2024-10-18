/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:22:27 by norban            #+#    #+#             */
/*   Updated: 2024/07/13 17:34:13 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rush.h>

char	*ft_substr(char *side, int start, int end)
{
	int			i;
	static char	str[8];

	i = 0;
	while (start <= end)
	{
		str[i] = side[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_first(char *side)
{
	char	*str;

	str = ft_substr(side, 0, 6);
	write(1, "     ", 5);
	write(1, str, 7);
	write(1, "\n     v v v v\n", 15);
}

void	ft_print_last(char *side)
{
	char	*str;

	str = ft_substr(side, 8, 14);
	write(1, "     ^ ^ ^ ^\n", 14);
	write(1, "     ", 5);
	write(1, str, 7);
	write(1, "\n", 1);
}

void	ft_formatline(int i, int *tab, char *side)
{
	int		j;
	int		k;
	char	c;

	k = i * 2;
	write(1, &side[k + 16], 1);
	write(1, " > |", 4);
	j = 0;
	while (j < 4)
	{
		c = tab[j] + 48;
		write(1, &c, 1);
		write(1, "|", 1);
		j++;
	}
	write(1, " < ", 3);
	write(1, &side[k + 24], 1);
	write(1, "\n", 1);
}

void	ft_print_result(int **tab, char *side)
{
	int	i;

	ft_print_first(side);
	i = 0;
	while (i < SIZE)
	{
		ft_formatline(i, tab[i], side);
		i++;
	}
	ft_print_last(side);
}
