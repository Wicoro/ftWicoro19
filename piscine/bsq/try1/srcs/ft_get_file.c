/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:48:01 by norban            #+#    #+#             */
/*   Updated: 2024/07/23 17:58:19 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

char	*ft_fill_file(char *file, char *file_address)
{
	int		f;
	int		r;
	char	a;
	int		i;

	f = open(file_address, 0);
	r = read(f, &a, 1);
	i = 0;
	while (r)
	{
		file[i] = a;
		r = read(f, &a, 1);
		i++;
	}
	file[i] = '\0';
	return (file);
}

char	*ft_get_file(char *file_address)
{
	int		f;
	int		r;
	char	a;
	int		file_size;
	char	*file;

	file_size = 0;
	f = open(file_address, 0);
	r = read(f, &a, 1);
	while (r)
	{
		file_size++;
		r = read(f, &a, 1);
	}
	close(f);
	file = malloc(sizeof(char) * (file_size + 1));
	if (!file)
		return (0);
	return (ft_fill_file(file, file_address));
}
