/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:31:00 by norban            #+#    #+#             */
/*   Updated: 2025/01/17 19:24:55 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if ((map->tiles[i]->coord->x == 0
			|| map->tiles[i]->coord->x == map->width - 1
			|| map->tiles[i]->coord->y == 0
			|| map->tiles[i]->coord->y == map->height - 1)
			&& map->tiles[i]->value != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_map *map)
{	
	if (!map || check_border(map) == 0)
		return (free(map), 0);
	if (check_road(map) == 0)
		return (free(map), 0);
	return (1);
}
