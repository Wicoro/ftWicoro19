/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:24:33 by norban            #+#    #+#             */
/*   Updated: 2024/10/27 18:19:45 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
void	ft_strncat(char **dest, char **str, int size);
char	*ft_strdup(char *str);
int		get_buf_last_i(char **buf, int size);
int		process_rest_to_line(char **buf, char **line);
char	*get_next_line(int fd);

#endif
