/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:42:51 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 10:19:37 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i);

void	ft_print_numbers(void)
{
	int	i;

	i = 48;
	while (i <= 57)
		ft_putchar(i++);
}

/*
int	main()
{
	ft_print_numbers();
}*/