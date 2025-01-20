/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:48:41 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:19:23 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_collectible(t_game *game, int sprite_i, t_tile *tile)
{
	if (!game->sprites[sprite_i])
	{
		game->sprites[sprite_i] = malloc(sizeof(t_sprite));
		if (!game->sprites[sprite_i])
			return ;
		game->sprites[sprite_i]->coord = malloc(sizeof(t_coord));
		if (!game->sprites[sprite_i]->coord)
			return ;
		game->sprites[sprite_i]->coord->x = tile->coord->x * 100;
		game->sprites[sprite_i]->coord->y = tile->coord->y * 100;
	}
	game->sprites[sprite_i]->state = 0;
}

void	reset_collectibles_state(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->c_nb)
	{
		game->sprites[3 + i]->state = 0;
		i++;
	}
}

void	create_collectible_list(t_game *game)
{
	int	i;
	int	sprite_i;

	i = 0;
	sprite_i = 3;
	while (game->map->tiles[i])
	{
		if (game->map->tiles[i]->value == 'C'
			|| game->map->tiles[i]->value == 'c')
		{
			create_collectible(game, sprite_i, game->map->tiles[i]);
			sprite_i++;
		}
		i++;
	}
}

void	break_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->c_nb)
	{
		if (is_in_element(game->sprites[1], game->sprites[3 + i]) == 1
			&& game->sprites[3 + i]->state < 11)
		{
			game->sprites[3 + i]->state++;
			break ;
		}
		i++;
	}
}

void	display_collectible(t_game *game)
{
	int	i;

	i = 0;
	game->mined_coll = 0;
	while (i < game->map->c_nb)
	{
		if (game->sprites[3 + i]->state <= 10)
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs[11 + game->sprites[3 + i]->state],
				game->sprites[3 + i]->coord->x, game->sprites[3 + i]->coord->y);
		if (game->sprites[3 + i]->state > 10)
			game->mined_coll++;
		i++;
	}
}
