/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by norban            #+#    #+#             */
/*   Updated: 2025/03/12 15:23:03 by norban           ###   ########.fr       */
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

void	free_tree(t_token **tree)
{
	t_token *crt;
	t_token *crt2;
	t_token	*left;

	if (!*tree)
		return ;
	crt = *tree;
	while (crt->data_type == PIPE)
	{
		left = crt->left;
		while (left->right && left->right->data_type != PIPE)
		{
			left = left->right;
			free(left->left->str);
			free(left->left);
		}
		free(left->str);
		free(left);
		crt2 = crt;
		crt = crt->right;
		free(crt2->str);
		free(crt2);
	}
	while (crt->right)
	{
		crt = crt->right;
		free(crt->left->str);
		free(crt->left);
	}
	free(crt->str);
	free(crt);
	*tree = NULL;
}

void	free_minishell(t_minishell *minishell)
{
	free_lexer(&minishell->lexer);
	free(minishell);
}