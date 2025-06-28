/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:12 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 15:59:37 by norban           ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# define WORD 0
# define PIPE 1
# define REDIRECTION 2
# define COMMAND 3

# define RED_IN 0
# define RED_OUT 1

# define HEREDOC 1
# define ADDF 2
# define OPENF 3
# define REPLACEF 4

extern int	g_last_exit_status;

typedef struct s_token
{
	int				data_type;
	char			*str;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

typedef struct s_hd_pipe
{
	int					pipe[2];
	struct s_hd_pipe	*prev;
	struct s_hd_pipe	*next;
}	t_hd_pipe;

typedef struct s_cmd
{
	char			**cmd_tab;
	int				*red_id;
	char			**red_file;
	t_hd_pipe		*hd_pipe;
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
	t_env		*env_start;
	t_token		*lexer;
	t_cmd		*cmd_list;
	int			return_val;
	int			end_flag;
}	t_datashell;

/*LEXER && PARSER*/
int			lexer(t_token **lexer, char **line);
int			parse_lexer(t_token *ref_node);
int			expander(t_datashell *data, int i);
char		*expander_str(char *src, t_datashell *data);
char		*ft_strnreplace(char *str, char *var_n, char *var_v, int start);
char		*get_var_name(char *str);
char		*get_var_value(char *str, t_env *env_start, int return_val);
char		*concat_cmd_str(t_token *node);
int			lexer_to_cmds(t_datashell *data);
int			process_heredoc(t_cmd *cmd, t_datashell *data);
char		*var_exchanger(char *str, int start, int len, t_datashell *data);
char		*loop_var_exchanger(char *str, t_datashell *data);
int			fill_hd_pipe(t_hd_pipe *crt, char *eof, t_datashell *da, t_cmd *c);
void		close_hd(t_hd_pipe *hd_pipe);
t_cmd		*create_cmd(t_token *crt, t_datashell *data);
int			get_red_count(t_token *ref_node);
int			get_redirection(t_token *ref_node, int *red_id, char **red_file);
int			fill_cmd_tab(t_token *crt, char **cmd_tab);
char		**allocate_cmd_tab(int cmd_len);
int			exchanger(char **new_str, int i, t_env *env_start, int return_val);
int			do_loop(char *line, char **str, char *eof, int *interrupted);
t_cmd		*fill_cmd(t_token *crt, t_cmd *cmd, t_datashell *data);

/*FREE*/
void		free_lexer(t_token **lexer);
void		free_minishell(t_datashell *data);
void		free_cmds(t_datashell *data);
void		free_cmd(t_cmd *cmd);
void		free_env(t_datashell *data);
void		free_hd_pipe(t_hd_pipe *hd_pipe);
void		free_exit(t_cmd *cmd, t_datashell *data, char *f, int n);

/*ENV*/
t_env		*get_env(char *env_name, t_env *env_start);
int			remove_env(t_env *env, t_datashell *data);
int			add_env(char *new_env_str, t_datashell *data);
int			env_to_llist(char **environment, t_datashell *data);
char		**get_full_env(t_env *env_start);
int			update_env(t_datashell *data, char *var_name, char *new_value);
int			get_env_size(t_env *env_start);
int			get_base_env(t_datashell *data);
void		check_oldpwd(t_datashell *data);

/*SIGNAL*/
void		signal_parent(void);
void		temporarily_ignore_signals(void);
void		restore_parent_signals(void);
void		signal_child(void);
void		signal_heredoc(void);

/*EXEC*/
int			exec_line(t_datashell *data);
int			exec_pipe(t_datashell *data);
int			p_child(int **pipe_tab, t_cmd *cmd, int i, t_datashell *data);
void		p_parent(pid_t *pids, int pipe_nbr, t_datashell *data);

/*EXEC UTILS*/
char		*get_path(char **split_cmd, char **split_env);
int			do_builtin(char **s_cmd, t_datashell *data, t_cmd *cmd);
void		free_tab(char **tab);
int			pipe_counter(t_cmd *cmd);
int			pipe_setter(int	**pipe_tab, int pipe_nbr);
void		free_itab(int **tab);
void		close_fd(int **pipe_tab);
int			check_builtin(t_datashell *data, char **cmd_tab, t_cmd *cmd);
int			call_handler(t_cmd *cmd);
void		ffree(char **cmd_tab, int **p_tab, char **env, char *path);
void		close_redi(t_datashell *data, int fd[2]);
char		**get_path_env(char **env);
char		*get_cmd(char **split_cmd, char **split_env);
int			input_handler(t_cmd *cmd);
int			output_handler(t_cmd *cmd);
int			in_out_handler(t_cmd *cmd);

/*BUILT_IN*/
int			bi_cd(char **path, t_env *env_start);
int			bi_env(t_datashell *data);
int			bi_export(char **str, t_datashell *data);
int			bi_pwd(void);
int			bi_unset(char **str, t_datashell *data);
int			bi_echo(char **split_echo);
int			bi_exit(t_datashell *data, char **cmd_tab);

/*BUILT_IN UTILS*/
int			value_fix(int n);
char		*get_key(const char *env_str);
char		*get_value(const char *env_str);
int			concat_env_exist(t_env **env, char *trimmed_key, char *arg);

#endif
