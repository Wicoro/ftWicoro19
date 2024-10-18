/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:29:06 by norban            #+#    #+#             */
/*   Updated: 2024/07/14 10:53:49 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rush.h>

solve_skyscrapper(struct row *board, int y)
{
	int	casecount;
	int	**cases;
	int	i;
	int y;

	if (y == SIZE && checkcol() == 1)
		return (1);
	else if (y == SIZE && checkcol() == 0)
		return (0)	
	cases = getcases(board[i].head, &casecount);
	i = 0;
	while (i < casecount)
	{
		board[y].tiles = cases[i];
		if (getvalidboard(board, i + 1) == 1)
			return (1);
		board[i] = {0, 0, 0, 0};
		i++;
	}
	return (0);
}

int	**ft_skycrapper(char *side)
{
	struct row	board[] = createboard(side);
	int			i;
	struct row	*validboard;

	validboard = solve_skyscrapper(board, 0);
}
