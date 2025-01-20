/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:37:46 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:06:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->sprites = malloc(sizeof(t_sprite *)
			* (4 + map->c_nb + map->z_nb));
	if (!game->sprites)
		return (free(game), NULL);
	game->map = map;
	ft_bzero(game->sprites, sizeof(t_sprite *)
		* (4 + map->c_nb + map->z_nb));
	game->width = map->width * 100;
	game->height = map->height * 100;
	game->movement = 0;
	game->move_str = ft_itoa(game->movement);
	game->mlx = mlx_init();
	game->win = NULL;
	return (game);
}

int	end_game(t_game *game)
{
	if (game->mlx)
	{
		destroy_all_images(game);
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free_all(game, game->map);
		exit(0);
	}
	return (0);
}

void	swap_view(t_game *game, int screen_id)
{
	if (screen_id == 1)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		game->win = mlx_new_window(game->mlx, 1920, 1080, "Wicoro's adventure");
		menu_manager(game);
	}
	else if (screen_id == 2)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		game->win = mlx_new_window(game->mlx, game->width,
				game->height, "Wicoro's adventure");
		ingame_manager(game);
	}
}
