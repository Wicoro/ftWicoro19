/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:22:57 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:14:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_obstacle(t_map *map, int x, int y, char side)
{
	int	i;

	i = 0;
	while (map->tiles[i])
	{
		if ((side == 'L' || side == 'R')
			&& ((map->tiles[i]->coord->x == x / 100
					&& map->tiles[i]->coord->y == y / 100
					&& map->tiles[i]->value == '1')
				|| (map->tiles[i]->coord->x == x / 100
					&& map->tiles[i]->coord->y == (y + 70) / 100
					&& map->tiles[i]->value == '1')))
			return (1);
		if ((side == 'U' || side == 'D')
			&& ((map->tiles[i]->coord->x == x / 100
					&& map->tiles[i]->coord->y == y / 100
					&& map->tiles[i]->value == '1')
				|| (map->tiles[i]->coord->x == (x + 70) / 100
					&& map->tiles[i]->coord->y == y / 100
					&& map->tiles[i]->value == '1')))
			return (1);
		i++;
	}
	return (0);
}

int	is_in_element(t_sprite *player, t_sprite *coll)
{
	int	i;

	i = 0;
	if ((coll->coord->x / 100 == player->coord->x / 100
			&& coll->coord->y / 100 == player->coord->y / 100)
		|| (coll->coord->x / 100 == player->coord->x / 100
			&& coll->coord->y / 100 == (player->coord->y + 70) / 100)
		|| (coll->coord->x / 100 == (player->coord->x + 70) / 100
			&& coll->coord->y / 100 == player->coord->y / 100)
		|| (coll->coord->x / 100 == (player->coord->x + 70) / 100
			&& coll->coord->y / 100 == (player->coord->y + 70) / 100))
		return (1);
	i++;
	return (0);
}
