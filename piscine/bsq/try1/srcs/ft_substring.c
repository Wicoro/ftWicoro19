/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:23:55 by norban            #+#    #+#             */
/*   Updated: 2024/07/24 20:49:52 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

char	*ft_substring(char *str, int end)
{
	int		i;
	char	*substr;

	substr = malloc(sizeof(char) * (end + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < end)
	{
		substr[i] = str[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
