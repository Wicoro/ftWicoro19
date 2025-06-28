/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:33:16 by norban            #+#    #+#             */
/*   Updated: 2025/06/13 20:16:19 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && (str[i] != '=' && str[i] != '+'))
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] == '+' && str[i + 1] && str[i + 1] != '=')
		return (0);
	return (1);
}

static void	print_export_sorted(t_env *env_list)
{
	char	**env_tab;
	char	*key;
	char	*val;
	int		i;

	env_tab = get_full_env(env_list);
	if (!env_tab)
		return ;
	sortstrings(env_tab, get_env_size(env_list));
	i = -1;
	while (env_tab[++i])
	{
		if (ft_strncmp(env_tab[i], "_=", 2) != 0)
		{
			key = get_key(env_tab[i]);
			printf("declare -x  %s", key);
			free(key);
			val = get_value(env_tab[i]);
			if (val)
				printf("=\"%s\"", val);
			free(val);
			printf("\n");
		}
	}
	free_tab(env_tab);
}

static int	concat_env(char *key, char *arg, t_env **env, t_datashell *data)
{
	char	*trimmed_key;
	char	*new_env_str;
	char	*tmp;
	char	*arg_value;

	trimmed_key = ft_strtrim(key, "+");
	if (!trimmed_key)
		return (1);
	if (*env && concat_env_exist(env, trimmed_key, arg) == 1)
		return (free(trimmed_key), 1);
	else
	{
		arg_value = get_value(arg);
		if (!arg_value)
			return (free(trimmed_key), 1);
		tmp = ft_strjoin(trimmed_key, "=");
		new_env_str = ft_strjoin(tmp, arg_value);
		free(tmp);
		free(arg_value);
		if (!new_env_str)
			return (1);
		add_env(new_env_str, data);
		free(new_env_str);
	}
	return (free(trimmed_key), 0);
}

static int	update_or_add_env(const char *arg, t_datashell *data)
{
	char	*key;
	t_env	*env;

	key = get_key(arg);
	if (!key)
		return (free(key), 1);
	if (key)
		env = get_env(key, data->env_start);
	else
		env = NULL;
	if (env && !ft_strchr(arg, '='))
		return (free(key), 1);
	else if (env && key[ft_strlen(key) - 1] != '+')
	{
		free(env->str);
		env->str = ft_strdup((char *)arg);
	}
	else if (key[ft_strlen(key) - 1] == '+'
		&& concat_env(key, (char *) arg, &env, data) == 1)
		return (free(key), 1);
	else
		add_env((char *)arg, data);
	free(key);
	return (0);
}

int	bi_export(char **args, t_datashell *data)
{
	int	i;
	int	status;

	status = 0;
	if (!args[1])
	{
		print_export_sorted(data->env_start);
		return (0);
	}
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			ft_putstr_fd("maxitotal: export: '", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			status = 1;
		}
		else
			status = update_or_add_env(args[i], data);
		i++;
	}
	return (status);
}
