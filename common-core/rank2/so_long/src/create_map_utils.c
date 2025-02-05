/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:35:54 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:51:11 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_tiles(char *line, t_tile **tiles, t_map *map, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (line)
	{
		j = 0;
		while (j < map->width)
		{
			tiles[i] = new_tile(line[j], map->width, i, j);
			i++;
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	tiles[i] = 0;
}

void	process_size(int *height, int *width, char *line, int *valid)
{
	(*height)++;
	if ((line[ft_strlen(line) - 1] == '\n'
			&& (size_t) * width != ft_strlen(line) - 1)
		|| (line[ft_strlen(line) - 1] != '\n'
			&& (size_t) * width != ft_strlen(line)))
		*valid = 0;
}
