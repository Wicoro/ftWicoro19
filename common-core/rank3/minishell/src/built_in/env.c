/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:36:41 by norban            #+#    #+#             */
/*   Updated: 2025/06/09 16:43:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_env(t_datashell *data)
{
	char	**env_list;
	int		i;

	env_list = get_full_env(data->env_start);
	if (!env_list)
		return (1);
	i = 0;
	while (env_list[i] && env_list[i])
	{
		if (ft_strchr(env_list[i], '='))
			printf("%s\n", env_list[i]);
		i++;
	}
	free_tab(env_list);
	return (0);
}
