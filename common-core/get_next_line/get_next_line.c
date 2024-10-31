/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:55:19 by norban            #+#    #+#             */
/*   Updated: 2024/10/31 15:29:59 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

const int	buf_s = BUFFER_SIZE;

int		get_buf_last_i(char **rest, int size)
{
	int	i;

	i = 0;
	while (i < size && (*rest)[i] && (*rest)[i] != '\n')
		i++;
	if (i == size)
		return (-1);
	return (i);
}

void	move_rest(char **rest, int i)
{
	char	*tmp;

	tmp = ft_strdup(*rest + i);
	if (!tmp)
	{
		free(*rest);
		*rest = NULL;
	}
	else if (!tmp[0])
	{
		free(*rest);
		*rest = NULL;
		return ;
	}
	else
	{
		free(*rest);
		*rest = tmp;
	}
}

int	process_rest_to_line(char **rest, char **line)
{
	*line = ft_strdup("");
	if (*rest)
	{
		if (get_buf_last_i(rest, buf_s) != -1)
		{
			ft_strncat(line, rest, get_buf_last_i(rest, buf_s));
			move_rest(rest, get_buf_last_i(rest, buf_s));
		}
		else
		{
			ft_strncat(line, rest, ft_strlen(*rest));
			move_rest(rest, ft_strlen(*line));
		}
		return (1);
	}
	return(2);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*rest;
	int			pro;
	int			r;

	pro = process_rest_to_line(&rest, &line);
	if (!line)
		return (NULL);
	if (pro == 1 && rest)
		return(move_rest(&rest, get_buf_last_i(&rest, buf_s) + 1), line);
	else
	{
		buf = malloc(sizeof(char) * buf_s);
		if (!buf)
			return (free(line), NULL);
		while (read(fd, buf, buf_s) > 0 && get_buf_last_i(&rest, buf_s) == -1)
		{
			ft_strncat(&line, &buf, buf_s);
			free(buf);
			buf = malloc(sizeof(char) * buf_s);
			if (!buf)
				return (free(line), NULL);
		}
		ft_strncat(&line, &buf, get_buf_last_i(&buf, buf_s));
		if (ft_strlen(line) == 0 && r <= 0)
			return (free(rest), free(buf), free(line), NULL);
		if (buf[0])		
			rest = ft_strdup(1 + buf + get_buf_last_i(&buf, buf_s));
	}
	return (line);
}

int	main(int ac, char **av)
{
	int	f = open(av[1], 0);
	char *s;

	ac = 0;
	while (1)
	{
		s = get_next_line(f);
		if (!s)
		{
			close(f);
			exit(1);
		}
		printf("%s\n", s);
		free(s);
	}
	close(f);
	return (0);
}
