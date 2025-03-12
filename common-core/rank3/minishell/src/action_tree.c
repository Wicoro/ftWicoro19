/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:56 by norban            #+#    #+#             */
/*   Updated: 2025/03/12 17:03:26 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_token	*get_previous_cmd_start(t_token *sep)
{
	sep = sep->left;
	while (sep && sep->left && sep->left->data_type != PIPE)
		sep = sep->left;
	return (sep);
}

int	split_lexer(t_token *sep, t_minishell **minishell)
{
	t_token	*crt;
	
	if (!(*minishell)->tree)
	{
		crt = sep;
		(*minishell)->tree = crt;
	}
	else
	{
		crt = (*minishell)->tree;
		while (crt->right)
			crt = crt->right;
		crt->right = sep;
		crt = crt->right;
	}
	crt->left = get_previous_cmd_start(sep);
	crt->right = NULL;
	return (0);
}

void	process_lexer_to_tree(t_minishell *minishell)
{
	t_token *sep;
	t_token *tmp;

	sep = minishell->lexer;
	while (sep && sep->right)
	{
		tmp = sep->right;
		if (sep->data_type == PIPE)
			split_lexer(sep, &minishell);
		sep = tmp;
	}
	while (sep->left && sep->left->data_type != PIPE)
		sep = sep->left;
	if (minishell->tree && minishell->tree->data_type == PIPE)
	{
		tmp = minishell->tree;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = sep;
	}
	else if (!minishell->tree)
		minishell->tree = minishell->lexer;
	printf("%s | %s\n", minishell->tree->str, minishell->lexer->str);
	t_token *print;
	int id = 0;
	print = minishell->tree;
	while (print)
	{
		if (print->data_type == PIPE)
			printf("%d : %d -> %s\n", id, print->data_type, print->str);
		else
		{
			tmp = print;
			printf("%d :", id);
			while (tmp && tmp->data_type != PIPE)
			{
				printf(" -> %s (%d)", tmp->str, tmp->data_type);
				tmp = tmp->right;
			}
			printf("\n");
			break;
		}
		id++;
		if (print && print->data_type == PIPE)
		{
			tmp = print->left;
			printf("%d :", id);
			while (tmp && tmp->data_type != PIPE)
			{
				printf(" -> %s (%d)", tmp->str, tmp->data_type);
				tmp = tmp->right;
			}
			printf("\n");
		}
		if (print->right && print->right->data_type != PIPE)
		{
			tmp = print->right;
			printf("%d :", id);
			while (tmp)
			{
				printf(" -> %s (%d)", tmp->str, tmp->data_type);
				tmp = tmp->right;
			}
			printf("\n");
			break;
		}
		print = print->right;
	}
}
