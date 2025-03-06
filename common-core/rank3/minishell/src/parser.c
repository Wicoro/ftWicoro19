/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:58:05 by norban            #+#    #+#             */
/*   Updated: 2025/03/06 14:23:03 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_lexer(t_minishell *minishell)
{
	t_token *crt;
	
	crt = minishell->lexer;
	while (crt->right)
	{
		if ((crt->data_type == REDIRECTION
			&& crt->right->data_type != WORD)
			|| (crt->data_type == PIPE && crt->right->data_type == PIPE))
		{
			printf("parse error\n");
			free_lexer(&minishell->lexer);
			return (1);
		}
		crt = crt->right;
	}
	if (minishell->lexer->data_type == PIPE || crt->data_type == PIPE
		|| crt->data_type == REDIRECTION)
	{
		printf("parse error\n");
		free_lexer(&minishell->lexer);
		return (1);
	}
	return (0);
}