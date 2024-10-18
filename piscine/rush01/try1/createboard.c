/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:54:21 by norban            #+#    #+#             */
/*   Updated: 2024/07/14 13:56:39 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rush.h>

int	getpositiverowcase(int start, int end)
{
	if (start == 1)
	{
		if (end == 4)
			return (1);
		if (end == 3)
			return (2);
		if (end == 2)
			return (3);
	}
	if (start == 2 && end == 3)
		return (4);
	return (0);
}

int	getnegativerowcase(start, end)
{
	if (start == 4 && end == 1)
		return (-1);
	if (start == 3)
	{
		if (end == 1)
			return (-2);
		if (end == 2)
			return (-4);
	}
	if (start == 2 && end == 1)
		return (-3);
	return (0);
}	

struct row	createrow(int y, int start, int end)
{
	struct row	row1;

	row1.tiles = {0, 0, 0, 0};
	row1.y = y;
	if (start < end)
		row1.head = getpositiverowcase(start, end);
	else if (end < start)
		row1.head = getnegativerowcase(start, end);
	else if (end == 2 && start == 2)
		row1.head = 5;
	else
		return (0);
	return (row1);
}

struct row	*createboard(char *side)
{
	struct row	rows[SIZE];
	int			i;
	int			start;
	int			end;
	
	i = 0;
	while (i < SIZE)
	{
		start = side[(2 * i) + 16] + 48;
		end = side[(2 * i) + 24] + 48;
		rows[i] = createrow(i + 1, start, end);
		i++;
	}
	return (rows);
}
