/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:23:31 by norban            #+#    #+#             */
/*   Updated: 2025/06/13 20:23:57 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_utils(int *search_f, char **searched, const char *env_name)
{
	*search_f = 0;
	if (env_name[ft_strlen(env_name) - 1] == '+')
	{
		*searched = ft_strtrim(env_name, "+");
		*search_f = 1;
	}
	else
		*searched = (char *)env_name;
	if (!(*searched))
		return (1);
	return (0);
}

t_env	*get_env(char *env_name, t_env *env_start)
{
	t_env	*crt;
	char	*searched;
	int		search_flag;
	int		found;

	crt = env_start;
	if (get_env_utils(&search_flag, &searched, env_name) == 1)
		return (NULL);
	found = 0;
	while (crt)
	{
		if (ft_strncmp(searched, crt->str, ft_strlen(searched)) == 0
			&& (crt->str[ft_strlen(searched)] == '='
				|| !crt->str[ft_strlen(searched)]))
			found = 1;
		if (found == 1)
			break ;
		crt = crt->next;
	}
	if (search_flag)
		free(searched);
	if (found)
		return (crt);
	return (NULL);
}
