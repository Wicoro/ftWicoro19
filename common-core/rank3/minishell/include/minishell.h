/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:12 by norban            #+#    #+#             */
/*   Updated: 2025/03/07 15:15:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# define WORD 0
# define PIPE 1
# define REDIRECTION 2

# define RED_IN 0
# define RED_OUT 1

typedef struct s_token
{
	int				data_type;
	char			*str;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

typedef struct s_env
{
	char			*str;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	t_env	*env_start;
	t_token	*tree;
	t_token	*lexer;
}	t_minishell;

//lexer
int		lexer(t_token **lexer, char *line);
int		parse_lexer(t_minishell *minishell);

//tree
void	process_lexer_to_tree(t_minishell *minishell);

//free
void	free_lexer(t_token **lexer);
void	free_tree(t_token **tree);
void	free_minishell(t_minishell *minishell);

#endif