/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:04:51 by norban            #+#    #+#             */
/*   Updated: 2025/01/17 19:23:27 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_exit(t_game *game)
{
	int	i;
	
	game->sprites[2] = malloc(sizeof(t_sprite));
	if (!game->sprites[2])
		return ;
	game->sprites[2]->coord = malloc(sizeof(t_coord));
	if (!game->sprites[2]->coord)
		return ;
	i = 0;
	while (game->map->tiles[i])
	{
		if (game->map->tiles[i]->value == 'E'
			|| game->map->tiles[i]->value == 'e')
		{
			game->sprites[2]->coord->x = game->map->tiles[i]->coord->x * 100;
			game->sprites[2]->coord->y = game->map->tiles[i]->coord->y * 100;
			break;
		}
		i++;
	}
	game->sprites[2]->state = 0;

}

void	display_exit(t_game *game)
{
	if (!game->sprites[2])
		create_exit(game);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs[6], 
		game->sprites[2]->coord->x, game->sprites[2]->coord->y);
}
