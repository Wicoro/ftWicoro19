/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:29:11 by norban            #+#    #+#             */
/*   Updated: 2025/01/17 16:56:43 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_cursor(t_game *game)
{
	game->sprites[0] = malloc(sizeof(t_sprite));
	if (!game->sprites[0])
		return (0);
	game->sprites[0]->coord = malloc(sizeof(t_coord));
	if (!game->sprites[0]->coord)
		return (0);
	game->sprites[0]->coord->x = 1425;
	game->sprites[0]->coord->y = 270;
	game->sprites[0]->state = 0;
	return (1);
}

void	display_cursor(t_game *game)
{
	if (!game->sprites[0] && create_cursor(game) == 0)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->imgs[3],
		game->sprites[0]->coord->x, game->sprites[0]->coord->y);
}

void	swap_cursor(t_game *game)
{
	if (game->sprites[0])
	{
		if (game->sprites[0]->coord->y == 270)
			game->sprites[0]->coord->y = 470;
		else
			game->sprites[0]->coord->y = 270;
	}
}