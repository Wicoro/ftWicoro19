/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:25:26 by norban            #+#    #+#             */
/*   Updated: 2025/04/02 17:24:07 by norban           ###   ########.fr       */
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
	env->str = str;
	return (env);
}

int	env_to_llist(char **environment, t_datashell *data)
{
	int		i;
	t_env	*crt;
	if (!environment || !environment[0])
		return (0);
	i = 0;
	data->env_start = extract_env(environment[i]);
	if (!data->env_start)
		return (1);
	i++;
	crt = data->env_start;
	while (environment[i])
	{
		crt->next = extract_env(environment[i]);
		if (!crt->next)
			return (1);
		i++;
		crt = crt->next;
	}
	return (0);
}

int	add_env(char *new_env_str, t_datashell *data)
{
	t_env	*crt;
	t_env	*new_env;
	
	crt = data->env_start;
	while (crt->next)
		crt = crt->next;
	new_env = extract_env(new_env_str);
	if (!new_env)
		return (1);
	crt->next = new_env;
	crt->next->prev = crt;
	return (0);
}

int	remove_env(t_env *env)
{
	if (env->prev)
		env->prev->next = env->next;
	if (env->next)
		env->next->prev = env->prev;
	free(env);
	env = NULL;
	return (0);
}
