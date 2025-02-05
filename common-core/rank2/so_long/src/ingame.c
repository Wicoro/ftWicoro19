/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:28:44 by norban            #+#    #+#             */
/*   Updated: 2025/01/22 18:56:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	next_frame(t_game *game)
{
	free(game->move_str);
	game->move_str = ft_itoa(game->movement);
	mlx_clear_window(game->mlx, game->win);
	set_background(game, 2);
	display_collectible(game);
	display_exit(game);
	display_mc(game);
	mlx_string_put(game->mlx, game->win, 10, 20, 0x000000, "Movements : ");
	mlx_string_put(game->mlx, game->win, 80, 20, 0x000000, game->move_str);
	if (is_in_element(game->sprites[1], game->sprites[2])
		&& game->mined_coll == game->map->c_nb)
		swap_view(game, 1);
}

int	ingame_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		swap_view(game, 1);
	else if (keycode == 100 || keycode == 113
		|| keycode == 115 || keycode == 122)
		move_mc(game, keycode);
	else if (keycode == 32)
		break_collectible(game);
	next_frame(game);
	return (keycode);
}

void	ingame_manager(t_game *game)
{
	set_background(game, 2);
	display_exit(game);
	game->movement = 0;
	if (!game->sprites[1])
	{
		display_mc(game);
		create_collectible_list(game);
	}
	else
	{
		reset_mc_pos(game);
		reset_collectibles_state(game);
		display_mc(game);
	}
	display_collectible(game);
	mlx_string_put(game->mlx, game->win, 10, 20, 0x000000, "Movements : ");
	mlx_string_put(game->mlx, game->win, 80, 20, 0x000000, game->move_str);
	mlx_key_hook(game->win, ingame_key, game);
	mlx_hook(game->win, 17, 0, end_game, game);
	mlx_loop(game->mlx);
}
