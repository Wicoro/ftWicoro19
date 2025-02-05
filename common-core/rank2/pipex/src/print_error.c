/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:29:16 by norban            #+#    #+#             */
/*   Updated: 2025/01/31 17:27:17 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int code)
{
	if (code == -1)
		ft_putstr_fd("Unidentified error : error code -1\n", STD_ERR);
	if (code == 0)
		ft_putstr_fd("Invalid arg_count : error code 0\n", STD_ERR);
	if (code == 1)
		ft_putstr_fd("Invalid filename : error code 1\n", STD_ERR);
	if (code == 2)
		ft_putstr_fd("Command not found : error code 2\n", STD_ERR);
	if (code == 3)
		ft_putstr_fd("Couldn't open file : error code 3\n", STD_ERR);
	if (code == 4)
		ft_putstr_fd("Failed to find path : error code 4\n", STD_ERR);
	if (code == 5)
		ft_putstr_fd("Failed to closed : error code 5\n", STD_ERR);
	exit(0);
}
