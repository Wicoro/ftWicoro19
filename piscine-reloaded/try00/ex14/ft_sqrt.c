/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:45:52 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 09:32:31 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	while (i * i != nb && nb / i >= i)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/**#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(70000000));
}**/
