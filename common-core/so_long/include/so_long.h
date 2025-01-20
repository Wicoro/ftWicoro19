/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:44:57 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:48:24 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_tile
{
	t_coord	*coord;
	char	value;
}	t_tile;

typedef struct s_map
{
	t_tile	**tiles;
	int		height;
	int		width;
	int		c_nb;
	int		z_nb;
}	t_map;

typedef struct s_sprite
{
	char	*path;
	int		state;
	t_coord	*coord;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*imgs[22];
	t_map		*map;
	int			width;
	int			height;
	int			movement;
	char		*move_str;
	int			mined_coll;
	t_sprite	**sprites;
}	t_game;

t_game	*create_game(t_map *map);
t_map	*create_map(char *av);
int		check_map(t_map *map);
int		check_road(t_map *map);
int		end_game(t_game *game);
void	create_images(t_game *game);
void	swap_view(t_game *game, int screen_id);
void	set_background(t_game *game, int screen_id);
void	menu_manager(t_game *game);
void	ingame_manager(t_game *game);
void	next_frame(t_game *game);
void	display_mc(t_game *game);
void	reset_mc_pos(t_game *game);
void	reset_collectibles_state(t_game *game);
void	display_exit(t_game *game);
void	create_collectible_list(t_game *game);
void	display_collectible(t_game *game);
void	display_cursor(t_game *game);
void	swap_cursor(t_game *game);
void	move_mc(t_game *game, int keycode);
int		is_in_element(t_sprite *player, t_sprite *coll);
int		is_in_obstacle(t_map *map, int x, int y, char side);
t_tile	**get_accessible(t_map *map, t_tile *mc_spawn);
void	free_all(t_game *game, t_map *map);
void	free_tiles(t_tile **tiles);
void	break_collectible(t_game *game);
t_tile	*get_mc_spawn(t_map *map);
void	destroy_all_images(t_game *game);
void	recursive_access_checker(t_map *map, t_tile **accessible, t_tile *tile);
t_tile	*new_tile(char value, int width, int i, int j);
void	create_tiles(char *line, t_tile **tiles, t_map *map, int fd);
void	process_size(int *height, int *width, char *line, int *valid);

#endif