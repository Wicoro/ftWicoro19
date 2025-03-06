/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:06:25 by norban            #+#    #+#             */
/*   Updated: 2025/02/17 15:11:34 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_child(t_token *parent, t_token *child)
{
	t_token	*crt;

	if (!parent->child)
		parent->child = child;
	else
	{
		crt = parent->child;
		while (crt->sibling)
			crt = crt->sibling;
		crt->sibling = child;
	}
}