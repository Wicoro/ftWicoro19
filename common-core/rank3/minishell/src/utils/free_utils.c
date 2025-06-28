/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 14:07:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_token **lexer)
{
	while (*lexer && (*lexer)->right)
	{
		*lexer = (*lexer)->right;
		if ((*lexer)->left->str)
			free((*lexer)->left->str);
		free((*lexer)->left);
	}
	if (*lexer)
	{
		if ((*lexer)->str)
			free((*lexer)->str);
		free(*lexer);
	}
	*lexer = NULL;
}

void	free_cmds(t_datashell *data)
{
	t_cmd	*crt;
	t_cmd	*next;

	crt = data->cmd_list;
	while (crt)
	{
		if (crt->next)
			next = crt->next;
		else
			next = NULL;
		free_cmd(crt);
		crt = next;
	}
	data->cmd_list = NULL;
}

void	free_env(t_datashell *data)
{
	t_env	*crt;
	t_env	*next;

	crt = data->env_start;
	while (crt)
	{
		next = crt->next;
		free(crt->str);
		free(crt);
		crt = next;
	}
}

void	free_minishell(t_datashell *data)
{
	if (data)
	{
		free_cmds(data);
		free_lexer(&data->lexer);
		free_env(data);
		free(data);
		data = NULL;
	}
}

void	free_hd_pipe(t_hd_pipe *hd_pipe)
{
	t_hd_pipe	*crt;

	if (hd_pipe)
	{
		close_hd(hd_pipe);
		crt = hd_pipe;
		while (crt->next)
		{
			free(crt->pipe);
			free(crt->prev);
			crt->prev = NULL;
			crt = crt->next;
		}
		free(crt);
		crt = NULL;
	}
	hd_pipe = NULL;
}
