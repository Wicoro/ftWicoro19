/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:18:22 by norban            #+#    #+#             */
/*   Updated: 2025/01/17 19:44:36 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	*new_tile(char value, int width, int i, int j)
{
	t_tile	*tile;
	int		y;
	
	tile = malloc(sizeof(t_tile));
	if (!tile)
		return (0);
	tile->value = value;
	tile->coord = malloc(sizeof(t_coord));
	if (!tile->coord)
		return (0);
	tile->coord->x = j;
	y = 0;
	while (i >= width)
	{
		i -= width;
		y++;
	}
	tile->coord->y = y;
	return (tile);
}

void	get_map_tiles(t_map *map, char *av)
{
	t_tile	**tiles;
	char	*line;
	int		fd;
	int		i;
	int		j;

	tiles = malloc(sizeof(t_tile*) * ((map->width * map->height) + 1));
	if (!tiles)
		return ;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
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
	map->tiles = tiles;
}

int	get_map_dimension(t_map *map, char *av)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	int		valid;
	
	fd = open(av, O_RDONLY);
	height = 0;
	valid = 1;
	line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	while (line)
	{
		height++;
		if ((line[ft_strlen(line) - 1] == '\n'
			&& (size_t) width != ft_strlen(line) -1)
			|| (line[ft_strlen(line) - 1] != '\n'
			&& (size_t) width != ft_strlen(line)))
			valid = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->width = width;
	map->height = height;
	return (valid);
}

int	get_map_elements_nb(t_map *map)
{
	int		i;
	int		exit;
	int		player;
	
	exit = 0;
	player = 0;
	i = 0;
	while (map->tiles[i])
	{
		if (map->tiles[i]->value == 'C' || map->tiles[i]->value == 'c')
			map->c_nb += 1;
		else if (map->tiles[i]->value == 'Z' || map->tiles[i]->value == 'z')
			map->z_nb += 1;
		else if (map->tiles[i]->value == 'E' || map->tiles[i]->value == 'e')
			exit++;
		else if (map->tiles[i]->value == 'P' || map->tiles[i]->value == 'p')
			player++;
		else if (map->tiles[i]->value != '1' && map->tiles[i]->value != '0')
			return (0);
		i++;
	}
	if (player != 1 || exit != 1 || map->c_nb < 1)
		return (0);	
	return (1);
}

t_map	*create_map(char *av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	if (get_map_dimension(map, av) == 0)
		return (0);
	get_map_tiles(map, av);
	map->c_nb = 0;
	map->z_nb = 0;
	if (get_map_elements_nb(map) == 0)
		return (0);
	return (map);
}