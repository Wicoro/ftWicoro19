/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:57:00 by norban            #+#    #+#             */
/*   Updated: 2024/10/15 17:42:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d", ft_islower(123));
	printf("\n");
	printf("%d", islower(123));
}
*/