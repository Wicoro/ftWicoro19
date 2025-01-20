/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_road_checker_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:28:55 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:24:54 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	contain_tile(t_tile **accessible, t_tile *tile)
{
	int	i;

	i = 0;
	while (accessible[i])
	{
		if (accessible[i] == tile)
			return (1);
		i++;
	}
	return (0);
}

void	add_tile(t_tile **accessible, t_tile *tile)
{
	int	i;

	i = 0;
	while (accessible[i])
		i++;
	accessible[i] = tile;
}

void	recursive_2(t_map *map, t_tile **accessible, t_tile *tile, int i)
{
	if (map->tiles[i]->coord->x == tile->coord->x
		&& map->tiles[i]->coord->y == tile->coord->y - 1
		&& map->tiles[i]->value != '1'
		&& contain_tile(accessible, map->tiles[i]) == 0)
		recursive_access_checker(map, accessible, map->tiles[i]);
	if (map->tiles[i]->coord->x == tile->coord->x
		&& map->tiles[i]->coord->y == tile->coord->y + 1
		&& map->tiles[i]->value != '1'
		&& contain_tile(accessible, map->tiles[i]) == 0)
		recursive_access_checker(map, accessible, map->tiles[i]);
}

void	recursive_access_checker(t_map *map, t_tile **accessible, t_tile *tile)
{
	int	i;

	add_tile(accessible, tile);
	i = 0;
	while (i < map->height * map->width)
	{
		if (map->tiles[i]->coord->x == tile->coord->x - 1
			&& map->tiles[i]->coord->y == tile->coord->y
			&& map->tiles[i]->value != '1'
			&& contain_tile(accessible, map->tiles[i]) == 0)
			recursive_access_checker(map, accessible, map->tiles[i]);
		if (map->tiles[i]->coord->x == tile->coord->x + 1
			&& map->tiles[i]->coord->y == tile->coord->y
			&& map->tiles[i]->value != '1'
			&& contain_tile(accessible, map->tiles[i]) == 0)
			recursive_access_checker(map, accessible, map->tiles[i]);
		recursive_2(map, accessible, tile, i);
		i++;
	}
}

t_tile	**get_accessible(t_map *map, t_tile *mc_spawn)
{
	t_tile	**accessible;

	accessible = malloc(sizeof(t_tile *) * (map->height * map->width) + 1);
	recursive_access_checker(map, accessible, mc_spawn);
	add_tile(accessible, 0);
	return (accessible);
}
