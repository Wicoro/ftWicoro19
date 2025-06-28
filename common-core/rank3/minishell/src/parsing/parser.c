/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:58:05 by norban            #+#    #+#             */
/*   Updated: 2025/05/04 19:36:22 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_lexer(t_token *ref_node)
{
	t_token	*crt;

	crt = ref_node;
	while (crt->right)
	{
		if ((crt->data_type == REDIRECTION && crt->right->data_type != WORD)
			|| (crt->data_type == PIPE && crt->right->data_type == PIPE))
		{
			ft_putstr_fd("minishell : syntax error near unexpected token '", 2);
			ft_putstr_fd(crt->str, 2);
			ft_putstr_fd("'\n", 2);
			return (1);
		}
		crt = crt->right;
	}
	if (ref_node->data_type == PIPE || crt->data_type == PIPE
		|| crt->data_type == REDIRECTION)
	{
		ft_putstr_fd("minishell : syntax error near unexpected token '", 2);
		ft_putstr_fd(crt->str, 2);
		ft_putstr_fd("'\n", 2);
		return (1);
	}
	return (0);
}
