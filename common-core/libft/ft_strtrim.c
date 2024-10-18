/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:17:58 by norban            #+#    #+#             */
/*   Updated: 2024/10/16 14:25:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, const char *set)
{
	if (ft_strchr(set, c))
		return (1);
	return (0);
}

static int	getnbtrim_start(const char *s1, const char *set, int s1_len)
{
	int	i;
	int	nb_trim;

	nb_trim = 0;
	i = 0;
	while (i < s1_len && isinset(s1[i], set) == 1)
	{
		i++;
		nb_trim++;
	}
	return (nb_trim);
}

static int	getnbtrim_end(const char *s1, const char *set, int s1_len)
{
	int	i;
	int	nb_trim;

	nb_trim = 0;
	i = s1_len - 1;
	while (i >= 0 && isinset(s1[i], set) == 1)
	{
		i--;
		nb_trim++;
	}
	return (nb_trim);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		nb_trim_s;
	int		nb_trim_e;
	int		len;

	len = ft_strlen(s1);
	nb_trim_s = getnbtrim_start(s1, set, len);
	if (nb_trim_s == len)
		return (ft_strdup(""));
	nb_trim_e = getnbtrim_end(s1, set, len);
	if (len - nb_trim_s - nb_trim_e == 0)
		len++;
	str = ft_substr(s1, nb_trim_s, len - nb_trim_s - nb_trim_e);
	return (str);
}

// #include "ft_substr.c"
// #include "ft_strchr.c"
// #include "ft_strlen.c"
// #include <stdio.h>
// #include "ft_strdup.c"

// int main()
// {
// 	char *set = "";
// 	char *str = "";
// 	printf("%s", ft_strtrim(str, set));
// }