/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:12 by norban            #+#    #+#             */
/*   Updated: 2025/04/16 16:40:30 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# define WORD 0
# define PIPE 1
# define REDIRECTION 2
# define COMMAND 3

# define RED_IN 0
# define RED_OUT 1

typedef struct s_token
{
	int				data_type;
	char			*str;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

typedef struct s_cmd
{
	char			*str;
	int				*red_id;
	char			**red_file;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*str;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_datashell
{
	t_env	*env_start;
	t_token	*lexer;
	t_cmd	*cmd_list;
}	t_datashell;

//lexing + parsing
int		lexer(t_token **lexer, char **line);
int		parse_lexer(t_token *ref_node);
int		expander(t_token *lexer, t_env *env_start);
char	*concat_cmd_str(t_token *node);
int		lexer_to_cmds(t_datashell *data);

//free
void	free_lexer(t_token **lexer);
void	free_minishell(t_datashell *data);
void	free_cmds(t_datashell *data);

//env
t_env	*get_env(char *env_name, t_env *env_start);
int		remove_env(t_env *env);
int		add_env(char *new_env_str, t_datashell *data);
int		env_to_llist(char **environment, t_datashell *data);

//utils
void	signal_handler(void);

#endif