/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:51 by norban            #+#    #+#             */
/*   Updated: 2024/07/14 10:45:26 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <stdlib.h>

int			**ft_skyscrapper(char *size);
void		ft_print_result(int **tab, char *size);
struct row	*createboard(char *side);
int			*getcases(int head, int *size);

# define SIZE 4

struct row
{
	int y;
	int tiles[4];
	int head;
}

#endif
