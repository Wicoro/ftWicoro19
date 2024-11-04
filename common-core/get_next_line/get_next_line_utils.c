/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:15:40 by norban            #+#    #+#             */
/*   Updated: 2024/11/04 23:22:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i])
		i++;
	return (i);
}

int	ft_strncat(char **dest, char **str, int str_size)
{
	char	*n_line;
	int		i;
	int		j;
	int		k;

	n_line = malloc(ft_strlen(*dest) + str_size + 1);
	if (!n_line)
		return (0);
	i = 0;
	k = 0;
	while (i < ft_strlen(*dest))
		n_line[k++] = (*dest)[i++];
	j = 0;
	while (j < str_size && (*str)[j])
		n_line[i++] = (*str)[j++];
	n_line[i] = '\0';
	free(*dest);
	*dest = n_line;
	return (1);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (n-- > 0)
		*(ptr++) = 0;
}

void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
