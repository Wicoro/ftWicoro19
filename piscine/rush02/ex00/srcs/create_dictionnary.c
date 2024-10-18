/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionnary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:37:06 by norban            #+#    #+#             */
/*   Updated: 2024/07/22 21:42:43 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rush.h"

char	*fill_dict(int size, char *file)
{
	int		f;
	int		r;
	char	a;
	int		i;
	char	*dict;

	dict = malloc(sizeof(char) * (size + 1));
	if (!dict)
		return (0);
	i = 0;
	f = open(file, 0);
	r = read(f, &a, 1);
	while (r)
	{
		dict[i] = a;
		r = read(f, &a, 1);
		i++;
	}
	dict[i] = '\0';
	return (dict);
}

char	*get_dict(char *file)
{
	int		f;
	int		r;
	char	a;
	int		i;
	char	*dict;

	i = 0;
	f = open(file, 0);
	r = read(f, &a, 1);
	while (r)
	{
		i++;
		r = read(f, &a, 1);
	}
	close(f);
	dict = fill_dict(i, file);
	return (dict);
}

char	*get_name(char *str)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	j = 0;
	name = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!name)
		return (0);
	while (str[i])
	{
		if (!(str[i] == ' ' && str[i - 1] == ' '))
		{
			name[j] = str[i];
			j++;
		}
		i++;
	}
	name[j] = '\0';
	return (name);
}

char	*get_val(char *str)
{
	int		i;
	int		val_size;
	int		j;
	char	*val;

	i = 0;
	val_size = 1;
	while (str[i] && str[i] != ' ' && str[i] != ':')
	{
		i++;
		val_size++;
	}
	i--;
	j = 0;
	val = malloc(sizeof(char) * val_size);
	if (!val)
		return (0);
	while (j <= i)
	{
		val[j] = str[j];
		j++;
	}
	val[j] = '\0';
	return (val);
}

t_nb_dict	*ft_create_dictionnary(char *file)
{
	t_nb_dict	*map;
	char		**dict_lines;
	int			i;
	char		*dict;

	dict = get_dict(file);
	dict_lines = ft_split(dict, "\n");
	free(dict);
	i = 0;
	while (dict_lines[i])
		i++;
	map = malloc(sizeof(t_nb_dict) * (i));
	if (!map)
		return (0);
	i = 0;
	while (dict_lines[i + 1])
	{
		map[i].val = get_val(dict_lines[i]);
		map[i].val_size = ft_strlen(map[i].val);
		map[i].name = get_name(dict_lines[i]);
		i++;
	}
	free(dict_lines);
	map[i].name = 0;
	return (map);
}
