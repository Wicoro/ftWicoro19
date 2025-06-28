/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:27:58 by norban            #+#    #+#             */
/*   Updated: 2025/06/10 17:18:07 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_cd(char *path)
{
	if (chdir(path) != 0)
	{
		ft_putstr_fd("maxitotal: cd: ", 2);
		perror(path);
		return (1);
	}
	return (0);
}

int	bi_cd(char **path, t_env *env_start)
{
	t_env	*home;
	char	*home_path;
	int		ret;

	if (!path[1] || ft_strncmp(path[1], "~", 2) == 0)
	{
		home = get_env("HOME", env_start);
		if (!home)
			return (ft_putstr_fd("maxitotal: cd: HOME not set\n", 2), 1);
		home_path = get_value(home->str);
		ret = make_cd(home_path);
		free(home_path);
		return (ret);
	}
	if (path[1] && path[2])
		return (ft_putstr_fd("maxitotal: cd : too many arguments\n", 2), 1);
	return (make_cd(path[1]));
}
