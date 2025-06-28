/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:33:16 by norban            #+#    #+#             */
/*   Updated: 2025/06/10 17:17:27 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_unset(char **vars_to_unset, t_datashell *data)
{
	int		i;
	t_env	*to_remove;

	i = 1;
	while (vars_to_unset[i])
	{
		to_remove = get_env(vars_to_unset[i], data->env_start);
		if (to_remove && ft_strncmp(to_remove->str, "_=", 2) != 0)
			remove_env(to_remove, data);
		i++;
	}
	return (0);
}
