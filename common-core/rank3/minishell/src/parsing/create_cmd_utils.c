/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:53:21 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 14:14:12 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**allocate_cmd_tab(int cmd_len)
{
	char	**cmd_tab;

	cmd_tab = malloc(sizeof(char *) * (cmd_len + 1));
	if (!cmd_tab)
		return (NULL);
	cmd_tab[cmd_len] = NULL;
	return (cmd_tab);
}

int	fill_cmd_tab(t_token *crt, char **cmd_tab)
{
	int		i;
	t_token	*temp;

	temp = crt;
	i = 0;
	while (temp && temp->data_type != PIPE)
	{
		if (temp->data_type == WORD
			&& (!temp->left || temp->left->data_type != REDIRECTION))
		{
			cmd_tab[i] = ft_strdup(temp->str);
			if (!cmd_tab[i])
				return (-1);
			i++;
		}
		temp = temp->right;
	}
	return (i);
}
