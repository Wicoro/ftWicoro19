/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:43:26 by norban            #+#    #+#             */
/*   Updated: 2025/04/02 15:35:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *str, t_env *env_start)
{
	t_env	*crt;

	crt = env_start;
	while (crt)
	{
		if (ft_strncmp(str + 1, crt->str, ft_strlen(str) - 1) == 0)
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
	while (str[i] && str[i] != ' ' && str[i] != '\"' && str[i] != '\'')
		i++;
	var_name = ft_substr(str, 1, i - 1);
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
	
	new_str = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(var_name) + ft_strlen(var_value) + 1));
	i = 0;
	j = 0;
	k = 0;
	while (str[j] && str[i] && i < start)
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

char	*var_exchanger(char *str, t_env *env_start, int start, int len)
{
	int		i;
	char	*var_name;
	char	*var_value;
	char	*new_str;
	char	*new_str2;

	i = start;
	if (!str)
		return (NULL);
	new_str = ft_strdup(str);
	while (new_str[i] && i < len)
	{
		if (new_str[i] == '$' && new_str[i + 1])
		{
			var_name = get_var_name(&new_str[i]);
			var_value = get_var_value(var_name, env_start);
			new_str2 = ft_strdup(new_str);
			free(new_str);
			new_str = ft_strnreplace(new_str2, var_name, var_value, i);
			free(new_str2);
			if (!new_str)
				return (NULL);
			free(var_name);
			free(var_value);
			i = -1;
		}
		i++;
	}
	return (new_str);
}

int	squote_expander(char **str, int trim_start)
{
	char	*new_str;
	int		len;
	
	len = 0;
	while (str[0][trim_start + len + 1] != '\'')
		len++;
	new_str = ft_strnreplace(str[0], "'", "", trim_start);
	free(*str);
	*str = new_str;
	new_str = ft_strnreplace(str[0], "'", "", trim_start);
	free(*str);
	*str = new_str;
	return (--len);
}

int	dquote_expander(char **str, int trim_start, t_env *env_start)
{
	char	*new_str;
	int		quote_len;
	
	quote_len = 1;
	while (str[0][trim_start + quote_len] && str[0][trim_start + quote_len] != '"')
		quote_len++;
	new_str = var_exchanger(str[0], env_start, trim_start, quote_len);
	free(*str);
	*str = new_str;
	new_str = ft_strnreplace(str[0], "\"", "", trim_start);
	free(*str);
	*str = new_str;
	new_str = ft_strnreplace(str[0], "\"", "", trim_start);
	free(*str);
	*str = new_str;
	return (ft_strlen(*str));
}

int	expander(t_token *lexer, t_env *env_start)
{
	int		i;
	t_token	*crt;
	char	*new_str;

	crt = lexer;
	while (crt && crt->str[i])
	{
		i = 0;
		while (crt->str && crt->str[i])
		{
			if (crt->str[i] == '\'')
				i = squote_expander(&crt->str, i);
			else if (crt->str[i] == '"')
				i = dquote_expander(&crt->str, i, env_start);
			else if (crt->str[i] == '$')
			{
				new_str = var_exchanger(crt->str, env_start, i, 2);
				free(crt->str);
				crt->str = new_str;
			}
			i++;
		}
		i = 0;
		crt = crt->right;
	}
	return (0);
}
