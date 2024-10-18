/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:42:40 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 10:18:09 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i)
{
	write(1, &i, 1);
}

void	ft_print_alphabet(void)
{
	int	i;

	i = 97;
	while (i <= 122)
		ft_putchar(i++);
}
/**int main()
{
	ft_print_alphabet();
}**/