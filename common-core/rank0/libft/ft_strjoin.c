/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:50:21 by norban            #+#    #+#             */
/*   Updated: 2024/10/15 10:32:00 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "ft_strlcpy.c"
// #include "ft_strlcat.c"
// #include "ft_strlen.c"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char * s1 = "alpha";
// 	char * s2 = "alpha";
// 	printf("%s", ft_strjoin(s1, s2));
// }