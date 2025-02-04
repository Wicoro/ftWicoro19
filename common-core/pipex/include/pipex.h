/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:12 by norban            #+#    #+#             */
/*   Updated: 2025/01/30 14:16:53 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# define C_PATH "/bin/"
# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

void	print_error(int code);
char	*get_command(char *av, char **env);
char	*get_command_args(char *av);
int		is_args_valid(int ac, char **av);

#endif