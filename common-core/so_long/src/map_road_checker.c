/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_road_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:53:24 by norban            #+#    #+#             */
/*   Updated: 2025/01/16 02:45:07 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	*get_mc_spawn(t_map *map)
{
	int	i;
	
	i = 0;
	while (i < map->height * map->width)
	{
		if (map->tiles[i]->value == 'P' || map->tiles[i]->value == 'p')
			return (map->tiles[i]);
		i++;
	}
	return (0);
}

t_tile	**get_objectives(t_map *map)
{
	t_tile	**objectives;
	int		i;
	int		j;

	objectives = malloc(sizeof(t_tile*) * (map->c_nb + 2));
	if (!objectives)
		return (0);
	i = 0;
	j = 0;
	while (i < map->height * map->width)
	{
		if (map->tiles[i]->value == 'C' || map->tiles[i]->value == 'c'
			|| map->tiles[i]->value == 'E' || map->tiles[i]->value == 'e')
			objectives[j++] = map->tiles[i];
		i++;
	}
	objectives[j] = 0;
	return (objectives);
}

int	objectives_in_accessible(t_tile **objectives, t_tile **accessible)
{
	int	i;
	int	j;
	int	found;
	
	i = 0;
	while (objectives[i])
	{
		j = 0;
		found = 0;
		while (accessible[j])
		{
			if (objectives[i] == accessible[j])
				found = 1;
			j++;
		}
		if (found == 0)
			return (0);
		else
			found = 0;
		i++;
	}
	return (1);
}

int	check_road(t_map *map)
{
	t_tile	*mc_spawn;
	t_tile	**objectives;
	t_tile	**accessible;
	int		return_val;
	
	mc_spawn = get_mc_spawn(map);
	objectives = get_objectives(map);
	accessible = get_accessible(map, mc_spawn);
	return_val = objectives_in_accessible(objectives, accessible);
	free(objectives);
	free(accessible);
	return (return_val);
}