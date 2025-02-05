/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:02 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:08:29 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	menu_key(int keycode, t_game *game)
{
	if (keycode == 65307
		|| (keycode == 32 && game->sprites[0]->coord->y == 470))
		end_game(game);
	if (keycode == 122 || keycode == 115)
	{
		mlx_clear_window(game->mlx, game->win);
		set_background(game, 1);
		swap_cursor(game);
		display_cursor(game);
	}
	if (keycode == 32)
		swap_view(game, 2);
	return (keycode);
}

void	menu_manager(t_game *game)
{
	set_background(game, 1);
	display_cursor(game);
	mlx_key_hook(game->win, menu_key, game);
	mlx_hook(game->win, 17, 0, end_game, game);
	mlx_loop(game->mlx);
}
