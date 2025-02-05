/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:53 by norban            #+#    #+#             */
/*   Updated: 2024/11/05 17:14:37 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int		ft_strlen(char *str);
int		ft_strncat(char **dest, char **str, int size);
char	*ft_strdup(char *str);
int		getlast(char **buf, int size);
int		process_rest_to_line(char **buf, char **line, int fd);
char	*get_next_line(int fd);
void	ft_bzero(void *b, long n);
void	free_ptr(char **ptr);

#endif
