/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:41:42 by norban            #+#    #+#             */
/*   Updated: 2025/01/17 15:08:11 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_ingame_background(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->tiles[i])
	{
		if (game->map->tiles[i]->value == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->imgs[5], 
				game->map->tiles[i]->coord->x * 100,
				game->map->tiles[i]->coord->y * 100);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->imgs[4],
				game->map->tiles[i]->coord->x * 100,
				game->map->tiles[i]->coord->y * 100);
		
		i++;
	}
}

void	set_menu_background(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->imgs[0], 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs[1], 1350, 200);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs[2], 1350, 400);
}

void	set_background(t_game *game, int screen_id)
{
	if (screen_id == 1)
		set_menu_background(game);
	else if (screen_id == 2)
		set_ingame_background(game);
}
