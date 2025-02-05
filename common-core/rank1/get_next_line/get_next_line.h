/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:24:33 by norban            #+#    #+#             */
/*   Updated: 2025/01/09 16:44:34 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*gnl_strdup(char *str);
int		get_buf_last_i(char **buf, int size);
int		process_rest_to_line(char **buf, char **line);
char	*get_next_line(int fd);
void	ft_bzero(void *b, long n);
void	gnl_free(char **ptr);

#endif
