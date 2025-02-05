/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:55:19 by norban            #+#    #+#             */
/*   Updated: 2024/11/05 17:50:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line_bonus.h"

int	getlast(char **rest, int size)
{
	int	i;

	i = 0;
	while (i < size && (*rest)[i] && (*rest)[i] != '\n')
		i++;
	if (i == size)
		return (-1);
	return (i);
}

void	move(char **rest, int i)
{
	char	*tmp;

	tmp = ft_strdup(*rest + i);
	if (!tmp || !tmp[0])
	{
		free_ptr(rest);
		free_ptr(&tmp);
	}
	else
	{
		free_ptr(rest);
		*rest = tmp;
	}
}

int	process_rest_to_line(char **rest, char **line, int fd)
{
	if (read(fd, 0, 0) < 0)
		return (3);
	*line = ft_strdup("");
	if (!(*line))
		return (0);
	if (*rest)
	{
		if (getlast(rest, BUFFER_SIZE) != -1)
		{
			ft_strncat(line, rest, getlast(rest, BUFFER_SIZE) + 1);
			move(rest, getlast(rest, BUFFER_SIZE));
		}
		else
		{
			ft_strncat(line, rest, ft_strlen(*rest));
			move(rest, ft_strlen(*line));
		}
		return (1);
	}
	return (2);
}

void	*read_next_line(char **buf, char **line, int r, int fd)
{
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (free_ptr(line), NULL);
	ft_bzero(*buf, (long) BUFFER_SIZE + 1);
	while (r > 0)
	{
		r = read(fd, *buf, BUFFER_SIZE);
		if (r == -1)
			return (free_ptr(buf), free_ptr(line), NULL);
		if (r == 0 || getlast(buf, BUFFER_SIZE) != -1)
			break ;
		ft_strncat(line, buf, BUFFER_SIZE);
		free_ptr(buf);
		*buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!(*buf))
			return (free_ptr(line), NULL);
		ft_bzero(*buf, (long) BUFFER_SIZE + 1);
	}
	if (!(*buf)[getlast(buf, BUFFER_SIZE)])
		ft_strncat(line, buf, getlast(buf, BUFFER_SIZE));
	else
		ft_strncat(line, buf, getlast(buf, BUFFER_SIZE) + 1);
	if ((ft_strlen(*line) == 0) && r <= 0)
		return (free_ptr(buf), free_ptr(line), NULL);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*rest[OPEN_MAX];
	int			pro;
	int			r;

	r = 1;
	pro = process_rest_to_line(&rest[fd], &line, fd);
	if (pro == 0)
		return (free_ptr(&(rest[fd])), NULL);
	if (pro == 1 && rest[fd])
		return (move(&rest[fd], getlast(&rest[fd], BUFFER_SIZE) + 1), line);
	else
	{
		if (pro == 3 || read_next_line(&buf, &line, r, fd) == NULL)
			return (free_ptr(&rest[fd]), NULL);
		if (buf[1] && getlast(&buf, BUFFER_SIZE) != -1)
			rest[fd] = ft_strdup(1 + buf + getlast(&buf, BUFFER_SIZE));
	}
	if (rest[fd] && ft_strlen(rest[fd]) == 0)
		free_ptr(&(rest[fd]));
	free_ptr(&buf);
	if (r <= 0 && ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

/*int	main(int ac, char **av)
{
	int	f = -1;
	char *s;

	ac = 0;
	av = NULL;
	while (1)
	{
		s = get_next_line(f);
		if (!s)
		{
			close(f);
			exit(1);
		}
		printf("%s", s);
		free(s);
		s = NULL;
	}
	close(f);
	return (0);
}*/
