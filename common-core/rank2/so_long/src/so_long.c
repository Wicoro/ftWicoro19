/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:38:04 by norban            #+#    #+#             */
/*   Updated: 2025/01/20 16:08:43 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_map	*map;

	if (ac != 2)
		return (ft_putstr_fd("Error\n", 1), 0);
	map = create_map(av[1]);
	if (check_map(map) == 0)
		return (ft_putstr_fd("Error\n", 1), 0);
	game = create_game(map);
	create_images(game);
	swap_view(game, 1);
}
