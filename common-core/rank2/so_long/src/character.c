/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:57:49 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:11:38 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_mc(t_game *game)
{
	game->sprites[1] = malloc(sizeof(t_sprite));
	if (!game->sprites[1])
		return (0);
	game->sprites[1]->coord = malloc(sizeof(t_coord));
	if (!game->sprites[1]->coord)
		return (0);
	game->sprites[1]->state = 0;
	reset_mc_pos(game);
	return (1);
}

void	reset_mc_pos(t_game *game)
{
	t_tile	*tmp;

	tmp = get_mc_spawn(game->map);
	game->sprites[1]->coord->x = (tmp->coord->x * 100) + 10;
	game->sprites[1]->coord->y = (tmp->coord->y * 100) + 10;
}

void	display_mc(t_game *game)
{
	if (!game->sprites[1] && create_mc(game) == 0)
		return ;
	if (game->sprites[1]->state == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs[7],
			game->sprites[1]->coord->x, game->sprites[1]->coord->y);
	else if (game->sprites[1]->state == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs[8],
			game->sprites[1]->coord->x, game->sprites[1]->coord->y);
	else if (game->sprites[1]->state == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs[9],
			game->sprites[1]->coord->x, game->sprites[1]->coord->y);
	else if (game->sprites[1]->state == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs[10],
			game->sprites[1]->coord->x, game->sprites[1]->coord->y);
}

void	move_mc2(t_game *game, int keycode)
{
	if (keycode == 100
		&& is_in_obstacle(game->map, game->sprites[1]->coord->x + 80,
			game->sprites[1]->coord->y, 'R') == 0)
	{
		game->sprites[1]->coord->x += 10;
		game->sprites[1]->state = 3;
		game->movement += 1;
	}
	else if (keycode == 113
		&& is_in_obstacle(game->map, game->sprites[1]->coord->x - 10,
			game->sprites[1]->coord->y, 'L') == 0)
	{
		game->sprites[1]->coord->x -= 10;
		game->sprites[1]->state = 2;
		game->movement += 1;
	}
}

void	move_mc(t_game *game, int keycode)
{
	if (keycode == 122
		&& is_in_obstacle(game->map, game->sprites[1]->coord->x,
			game->sprites[1]->coord->y - 10, 'U') == 0)
	{
		game->sprites[1]->coord->y -= 10;
		game->sprites[1]->state = 0;
		game->movement += 1;
	}
	else if (keycode == 115
		&& is_in_obstacle(game->map, game->sprites[1]->coord->x,
			game->sprites[1]->coord->y + 80, 'D') == 0)
	{
		game->sprites[1]->coord->y += 10;
		game->sprites[1]->state = 1;
		game->movement += 1;
	}
	else
		move_mc2(game, keycode);
}
