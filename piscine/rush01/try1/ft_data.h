/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:41:49 by norban            #+#    #+#             */
/*   Updated: 2024/07/14 10:54:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H
# define CASE01 {4, 3, 2, 1} 
# define CASE02 {4, 2, 3, 1} 
# define CASE03 {4, 3, 1, 2} 
# define CASE04 {4, 1, 3, 2} 
# define CASE05 {4, 1, 2, 3} 
# define CASE06 {4, 2, 1, 3} 
# define CASE07 {2, 4, 3, 1} 
# define CASE08 {3, 4, 2, 1} 
# define CASE09 {1, 4, 3, 2} 
# define CASE10 {3, 4, 1, 2} 
# define CASE11 {2, 4, 1, 3} 
# define CASE12 {1, 4, 2, 3}
# define CASE13 {1, 2, 3, 4}
# define CASE14 {1, 3, 2 ,4}
# define CASE15 {2, 1, 3, 4}
# define CASE16 {2, 3, 1, 4}
# define CASE17 {3, 2, 1, 4}
# define CASE18 {3, 1, 2, 4}
# define CASE19 {1, 3, 4, 2}
# define CASE20 {1, 2, 4, 3}
# define CASE21 {2, 3, 4, 1}
# define CASE22 {2, 1, 4, 3}
# define CASE23 {3, 1, 4, 2}
# define CASE24 {3, 2, 4, 1}

int	head1[][SIZE] = {
	CASE01
};

int	head2[][SIZE] = {
	CASE02,
	CASE03,
	CASE04
};

int	head3[][SIZE] = {
	CASE05,
	CASE06
};

int	head4[][SIZE] = {
	CASE07,
	CASE08,
	CASE09
};

int	head5[][SIZE] = {
	CASE10,
	CASE11,
	CASE12,
	CASE22,
	CASE23,
	CASE24
};

int	headn1[][SIZE] = {
	CASE13
};

int	headn2[][SIZE] = {
	CASE14,
	CASE15,
	CASE16
};

int	headn3[][SIZE] = {
	CASE17,
	CASE18
};

int	headn4[][SIZE] = {
	CASE19,
	CASE20,
	CASE21
};

#endif
