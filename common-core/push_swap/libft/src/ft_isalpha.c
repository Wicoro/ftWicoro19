/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:49:12 by norban            #+#    #+#             */
/*   Updated: 2024/10/15 17:42:55 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int c)
{
	if (ft_islower(c) == 1 || ft_isupper(c) == 1)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main()
{
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('1'));
}
*/