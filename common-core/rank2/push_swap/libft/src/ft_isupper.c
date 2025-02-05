/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:05:13 by norban            #+#    #+#             */
/*   Updated: 2024/10/15 17:43:10 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d", ft_isupper(65));
	printf("\n");
	printf("%d", isupper(65));
}
*/