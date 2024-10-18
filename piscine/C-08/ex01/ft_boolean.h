/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:57:47 by norban            #+#    #+#             */
/*   Updated: 2024/07/23 15:25:18 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN even
# define SUCCESS 0

typedef enum boolean
{
	FALSE,
	TRUE
}	t_bool;

t_bool	even(int nbr)
{
	if (nbr % 2 == 0)
		return (TRUE);
	return (FALSE);
}

#endif
