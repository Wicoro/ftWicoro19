/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:14:44 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 10:30:02 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_display_file.h"

void	ft_display_file(char *file)
{
	int		f;
	int		r;
	char	a;

	f = open(file, 0);
	r = read(f, &a, 1);
	while (r != 0)
	{
		ft_putchar(a);
		r = read(f, &a, 1);
	}
	close(f);
}
