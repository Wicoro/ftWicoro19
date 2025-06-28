/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:18:52 by norban            #+#    #+#             */
/*   Updated: 2025/06/10 17:16:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_size(t_env *env_start)
{
	int		i;
	t_env	*crt;

	if (!env_start)
		return (-1);
	i = 0;
	crt = env_start;
	while (crt)
	{
		i++;
		crt = crt->next;
	}
	return (i);
}

char	**get_full_env(t_env *env_start)
{
	char	**env;
	t_env	*crt;
	int		size;
	int		i;

	if (!env_start)
		return (NULL);
	size = get_env_size(env_start);
	env = malloc(sizeof(char *) * (size + 1));
	if (!env || size == -1)
		return (NULL);
	env[size] = NULL;
	crt = env_start;
	i = -1;
	while (++i < size)
	{
		env[i] = ft_strdup(crt->str);
		if (!env[i])
			return (free_tab(env), free(env), NULL);
		crt = crt->next;
	}
	return (env);
}

int	update_env(t_datashell *data, char *var_name, char *new_value)
{
	t_env	*edit;
	char	*tmp;
	char	*env_str;

	edit = get_env(var_name, data->env_start);
	if (!edit)
		return (1);
	tmp = ft_strjoin(var_name, "=");
	if (!tmp)
		return (1);
	env_str = ft_strjoin(tmp, new_value);
	free(tmp);
	if (!env_str)
		return (1);
	free(edit->str);
	edit->str = env_str;
	return (0);
}

int	get_base_env(t_datashell *data)
{
	char	*pwd;
	char	*buf;
	char	*tmp;

	buf = NULL;
	tmp = getcwd(buf, 1024);
	if (!tmp)
		return (1);
	pwd = ft_strjoin("PWD=", tmp);
	if (!pwd)
		return (free(buf), free(tmp), 1);
	free(buf);
	add_env(pwd, data);
	free(pwd);
	add_env("SHLVL=0", data);
	add_env("_=/usr/bin/env", data);
	add_env("OLDPWD", data);
	free(tmp);
	return (0);
}

void	check_oldpwd(t_datashell *data)
{
	t_env	*oldpwd;

	oldpwd = get_env("OLDPWD", data->env_start);
	if (!oldpwd)
		add_env("OLDPWD", data);
}
