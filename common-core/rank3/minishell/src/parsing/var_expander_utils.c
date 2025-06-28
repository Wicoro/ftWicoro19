/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expander_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:29:58 by norban            #+#    #+#             */
/*   Updated: 2025/06/17 17:20:16 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *str, t_env *env_start, int return_val)
{
	t_env	*crt;

	crt = env_start;
	if (ft_strlen(str) == 2 && str[1] == '?')
		return (ft_itoa(return_val));
	while (crt)
	{
		if (ft_strncmp(str + 1, crt->str, ft_strlen(str) - 1) == 0
			&& crt->str[ft_strlen(str) - 1] == '=')
			return (ft_substr(crt->str, ft_strlen(str),
					ft_strlen(crt->str) - ft_strlen(str)));
		crt = crt->next;
	}
	return (ft_strdup(""));
}

char	*get_var_name(char *str)
{
	int		i;
	char	*var_name;
	char	*var_name_extended;

	i = 1;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		var_name = ft_substr(str, 1, 1);
	}
	else
	{
		if (str[1] == '?')
			return (ft_strdup("$?"));
		while (str[i] && (ft_isalnum(str[i]) == 1
				|| str[i] == '_'))
			i++;
		var_name = ft_substr(str, 1, i - 1);
	}
	if (!var_name)
		return (NULL);
	var_name_extended = ft_strjoin("$", var_name);
	free(var_name);
	return (var_name_extended);
}

char	*ft_strnreplace(char *str, char *var_name, char *var_value, int start)
{
	int		i;
	int		j;
	int		k;
	char	*new_str;

	i = 0;
	j = 0;
	k = 0;
	new_str = malloc(sizeof(char)
			* (ft_strlen(str) - ft_strlen(var_name)
				+ ft_strlen(var_value) + 1));
	if (!new_str)
		return (NULL);
	while (str[j] && i < start)
		new_str[i++] = str[j++];
	while (str[j] && str[j] != var_name[0])
		new_str[i++] = str[j++];
	j += ft_strlen(var_name);
	while (var_value[k])
		new_str[i++] = var_value[k++];
	while (str[j])
		new_str[i++] = str[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*expander_str(char *src, t_datashell *data)
{
	char	*str;
	int		i;

	i = -1;
	if (!ft_strchr(src, '$'))
		return (ft_strdup(src));
	str = loop_var_exchanger(src, data);
	return (str);
}

char	*loop_var_exchanger(char *str, t_datashell *data)
{
	char	*new_str;
	char	*tmp_str;
	int		loop_count;
	int		i;

	loop_count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '$' && str[i + 1]
			&& str[i + 1] != '$' && str[i + 1] != '"')
			loop_count++;
	tmp_str = ft_strdup(str);
	if (!tmp_str)
		return (NULL);
	while (--loop_count >= 0)
	{
		new_str = var_exchanger(tmp_str, 0, ft_strlen(tmp_str), data);
		if (!new_str)
			return (free(tmp_str), NULL);
		if (ft_strncmp(new_str, tmp_str, ft_strlen(tmp_str) + 1) == 0)
			break ;
		free(tmp_str);
		tmp_str = new_str;
	}
	return (tmp_str);
}
