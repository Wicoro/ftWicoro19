/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:43:05 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 10:20:06 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i);

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar(80);
	else
		ft_putchar(78);
}

/**int main()
{
	ft_is_negative(-0);
}**/