/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:09:17 by norban            #+#    #+#             */
/*   Updated: 2025/03/06 13:20:22 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_image(t_game *game, char *path, int width, int height)
{
	void	*img;

	path = ft_strjoin("texture/", path);
	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	free(path);
	return (img);
}

void	create_images(t_game *game)
{
	game->imgs[0] = create_image(game, "background.xpm", 1920, 1080);
	game->imgs[1] = create_image(game, "play_button.xpm", 250, 80);
	game->imgs[2] = create_image(game, "quit_button.xpm", 250, 80);
	game->imgs[3] = create_image(game, "cursor.xpm", 250, 80);
	game->imgs[4] = create_image(game, "floor.xpm", 100, 100);
	game->imgs[5] = create_image(game, "lava.xpm", 100, 100);
	game->imgs[6] = create_image(game, "exit.xpm", 100, 100);
	game->imgs[7] = create_image(game, "mc_up.xpm", 100, 100);
	game->imgs[8] = create_image(game, "mc_down.xpm", 100, 100);
	game->imgs[9] = create_image(game, "mc_left.xpm", 100, 100);
	game->imgs[10] = create_image(game, "mc_right.xpm", 100, 100);
	game->imgs[11] = create_image(game, "collectible_0.xpm", 100, 100);
	game->imgs[12] = create_image(game, "collectible_1.xpm", 100, 100);
	game->imgs[13] = create_image(game, "collectible_2.xpm", 100, 100);
	game->imgs[14] = create_image(game, "collectible_3.xpm", 100, 100);
	game->imgs[15] = create_image(game, "collectible_4.xpm", 100, 100);
	game->imgs[16] = create_image(game, "collectible_5.xpm", 100, 100);
	game->imgs[17] = create_image(game, "collectible_6.xpm", 100, 100);
	game->imgs[18] = create_image(game, "collectible_7.xpm", 100, 100);
	game->imgs[19] = create_image(game, "collectible_8.xpm", 100, 100);
	game->imgs[20] = create_image(game, "collectible_9.xpm", 100, 100);
	game->imgs[21] = create_image(game, "collectible_10.xpm", 100, 100);
}

void	destroy_all_images(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 21)
	{
		mlx_destroy_image(game->mlx, game->imgs[i]);
		i++;
	}
}
