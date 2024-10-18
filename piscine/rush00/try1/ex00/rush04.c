/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamarkou <oamarkou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:36:23 by norban            #+#    #+#             */
/*   Updated: 2024/07/07 20:47:35 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_negative_input_error(void)
{
	char	*negative;
	int		i;

	i = 0;
	negative = "Input can't be smaller than 0\n";
	while (negative[i] != '\0')
	{
		ft_putchar(negative[i]);
		i++;
	}
}

void	ft_first_line(int x, int indexx)
{
	while (indexx <= x)
	{
		if (indexx == 1)
			ft_putchar('A');
		else if (indexx == x)
			ft_putchar('C');
		else
			ft_putchar('B');
		indexx++;
	}
}

void	ft_middle_line(int x, int indexx)
{
	while (indexx <= x)
	{
		if (indexx == 1 || indexx == x)
			ft_putchar('B');
		else
			ft_putchar(32);
		indexx++;
	}
}

void	ft_last_line(int x, int indexx)
{
	while (indexx <= x)
	{
		if (indexx == 1)
			ft_putchar('C');
		else if (indexx == x)
			ft_putchar('A');
		else
			ft_putchar('B');
		indexx++;
	}
}

void	rush(int x, int y)
{
	int	indexx;
	int	indexy;

	if (x < 0 || y < 0)
		ft_negative_input_error();
	indexx = 1;
	indexy = 1;
	while (indexy <= y)
	{
		indexx = 1;
		if (indexy == 1)
			ft_first_line(x, indexx);
		else if (indexy == y)
			ft_last_line(x, indexx);
		else
			ft_middle_line(x, indexx);
		if (x >= 0)
			ft_putchar('\n');
		indexy++;
	}
}
