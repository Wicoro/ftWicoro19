/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:54:12 by norban            #+#    #+#             */
/*   Updated: 2025/06/13 20:01:29 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key(const char *env_str)
{
	int	i;

	i = 0;
	while (env_str[i] && env_str[i] != '=')
		i++;
	return (ft_substr(env_str, 0, i));
}

char	*get_value(const char *env_str)
{
	int	i;

	i = 0;
	if (!ft_strchr(env_str, '='))
		return (NULL);
	while (env_str[i] && env_str[i] != '=')
		i++;
	if ((size_t)i == ft_strlen(env_str) - 1)
		return (ft_strdup(""));
	else
		return (ft_substr(env_str, i + 1, ft_strlen(env_str) - i - 1));
}

int	concat_env_exist(t_env **env, char *trimmed_key, char *arg)
{
	char	*old_env_str;
	char	*new_env_str;
	char	*tmp;
	char	*arg_value;

	old_env_str = get_value((*env)->str);
	if (!old_env_str)
		old_env_str = ft_strdup("");
	new_env_str = ft_strjoin(trimmed_key, "=");
	tmp = ft_strjoin(new_env_str, old_env_str);
	free(new_env_str);
	arg_value = get_value(arg);
	if (!arg_value)
		arg_value = ft_strdup("");
	new_env_str = ft_strjoin(tmp, arg_value);
	free(arg_value);
	free(tmp);
	free((*env)->str);
	if (!new_env_str)
		return (free(old_env_str), 1);
	(*env)->str = new_env_str;
	free(old_env_str);
	return (0);
}
