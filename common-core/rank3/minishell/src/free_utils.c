/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by norban            #+#    #+#             */
/*   Updated: 2025/03/06 14:08:32 by norban           ###   ########.fr       */
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

void	free_minishell(t_minishell *minishell)
{
	free_lexer(&minishell->lexer);
	free(minishell);
}