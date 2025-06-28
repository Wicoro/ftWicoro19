/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exchanger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:14:14 by norban            #+#    #+#             */
/*   Updated: 2025/06/12 18:10:38 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exchanger(char **new_str, int i, t_env *env_start, int return_val)
{
	char	*var_name;
	char	*var_value;
	char	*new_str2;

	var_name = get_var_name(&(*new_str)[i]);
	if (!var_name)
		return (1);
	var_value = get_var_value(var_name, env_start, return_val);
	if (!var_value)
		return (free(var_name), 1);
	new_str2 = ft_strdup(*new_str);
	if (!new_str2)
		return (free(*new_str), 1);
	free(*new_str);
	*new_str = ft_strnreplace(new_str2, var_name, var_value, i);
	free(new_str2);
	if (!(*new_str))
		return (1);
	free(var_name);
	free(var_value);
	return (0);
}

char	*var_exchanger(char *str, int start, int len, t_datashell *data)
{
	int		i;
	char	*new_str;

	i = start;
	if (!str)
		return (NULL);
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	while (new_str[i] && i < len)
	{
		if (new_str[i] == '$' && new_str[i + 1] != '$' && new_str[i + 1]
			&& (ft_isprint(new_str[i + 1])))
		{
			if (exchanger(&new_str, i, data->env_start, data->return_val) == 1)
				return (free(new_str), NULL);
			else
				return (new_str);
		}
		i++;
	}
	free(new_str);
	return (ft_strdup(str));
}
