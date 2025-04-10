/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by norban            #+#    #+#             */
/*   Updated: 2025/04/10 13:06:36 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_token **lexer)
{
	while (*lexer && (*lexer)->right)
	{
		*lexer = (*lexer)->right;
		free((*lexer)->left);
	}
	if (*lexer)
		free(*lexer);
	*lexer = NULL;
}

void	free_cmds(t_datashell *data)
{
	t_cmd	*crt;
	t_cmd	*next;
	
	crt = data->cmd_list;
	while (crt)
	{
		next = crt->next;
		free(crt);
		crt = next;
	}
}

void	free_env(t_datashell *data)
{
	t_env	*crt;
	t_env	*next;
	
	crt = data->env_start;
	while (crt)
	{
		next = crt->next;
		free(crt);
		crt = next;
	}
}

void	free_minishell(t_datashell *data)
{
	free_lexer(&data->lexer);
	free_env(data);
	free(data);
}
