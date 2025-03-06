/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:56 by norban            #+#    #+#             */
/*   Updated: 2025/03/06 15:38:17 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_tree(t_minishell **minishell)
{
	(*minishell)->tree = malloc(sizeof(t_token));
	(*minishell)->tree->data_type = -1;
}

void	add_left_to_tree(t_token *sep, t_minishell *minishell)
{
	t_token	*crt;
	
	if (!minishell->tree)
		create_tree(&minishell);
	crt = minishell->tree;
	while (crt->right)
		crt = crt->right;
	if (crt->data_type == -1)
	{
		crt->data_type = sep->data_type;
		
	}
}

int	process_lexer_to_tree(t_minishell *minishell)
{
	t_token *sep;

	sep = minishell->lexer;
	while (sep)
	{
		if (sep->data_type == PIPE)
		{
			add_to_tree(sep, minishell);
		}
		sep = sep->right;
	}
}
