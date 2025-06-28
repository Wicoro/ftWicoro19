/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:25:26 by norban            #+#    #+#             */
/*   Updated: 2025/06/13 20:23:41 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*extract_env(char *str)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->next = NULL;
	env->prev = NULL;
	env->str = ft_strdup(str);
	if (!env->str)
		return (free(env), NULL);
	return (env);
}

int	env_to_llist(char **environment, t_datashell *data)
{
	int		i;
	t_env	*crt;
	t_env	*new;

	data->env_start = NULL;
	if (!environment || !environment[0])
		return (get_base_env(data), 0);
	i = 0;
	data->env_start = extract_env(environment[i]);
	if (!data->env_start)
		return (1);
	i++;
	crt = data->env_start;
	while (environment[i])
	{
		new = extract_env(environment[i]);
		if (!new)
			return (1);
		new->prev = crt;
		crt->next = new;
		i++;
		crt = new;
	}
	check_oldpwd(data);
	return (0);
}

int	add_env(char *new_env_str, t_datashell *data)
{
	t_env	*crt;
	t_env	*new_env;

	new_env = extract_env(new_env_str);
	if (!new_env)
		return (1);
	if (!data->env_start)
	{
		data->env_start = new_env;
		return (0);
	}
	crt = data->env_start;
	while (crt->next)
		crt = crt->next;
	crt->next = new_env;
	new_env->prev = crt;
	return (0);
}

int	remove_env(t_env *env, t_datashell *data)
{
	if (!env)
		return (1);
	if (data->env_start == env)
		data->env_start = env->next;
	if (env->prev)
		env->prev->next = env->next;
	if (env->next)
		env->next->prev = env->prev;
	free(env->str);
	free(env);
	env = NULL;
	return (0);
}
