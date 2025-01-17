/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:58:13 by norban            #+#    #+#             */
/*   Updated: 2025/01/17 19:44:43 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_sprite **sprites)
{
	int	i;

	i = 0;
	while (sprites[i])
	{
		if (sprites[i]->coord)
			free(sprites[i]->coord);
		free(sprites[i]);
		i++;
	}
	free(sprites);
}

void	free_tiles(t_tile **tiles)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		free(tiles[i]->coord);
		free(tiles[i]);
		i++;
	}
	free(tiles);
}

void	free_map(t_map *map)
{
	free_tiles(map->tiles);
	free(map);
	map = NULL;
}

void	free_all(t_game *game, t_map *map)
{
	free_sprites(game->sprites);
	if (map)
		free_map(map);
	if (game->move_str)
		free(game->move_str);
	free(game->mlx);
	free(game);
}