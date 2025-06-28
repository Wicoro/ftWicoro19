/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:17:34 by norban            #+#    #+#             */
/*   Updated: 2025/06/13 20:18:19 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_status = 0;

t_datashell	*create_minishell(char **environment)
{
	t_datashell	*data;
	char		*env_lvl;
	int			env_lvl_i;
	char		*new_env_lvl;

	data = malloc(sizeof(t_datashell));
	if (!data)
		return (NULL);
	data->cmd_list = NULL;
	data->lexer = NULL;
	if (!environment)
		return (free(data), NULL);
	if (env_to_llist(environment, data) == 1)
		return (free(data), NULL);
	env_lvl = get_value(get_env("SHLVL", data->env_start)->str);
	env_lvl_i = ft_atoi(env_lvl);
	new_env_lvl = ft_itoa(env_lvl_i + 1);
	update_env(data, "SHLVL", new_env_lvl);
	data->return_val = 0;
	data->end_flag = -1;
	return (free(new_env_lvl), free(env_lvl), data);
}

int	check_process(t_datashell **data, char **line)
{
	if (g_last_exit_status == 130)
		(*data)->return_val = 130;
	g_last_exit_status = 0;
	if (*line && ft_strtrimlen(*line) == 0)
		return (free(*line), 1);
	else if (!(*line))
		return (bi_exit(*data, NULL), 1);
	return (0);
}

int	process_exec(t_datashell **data, char **line, int *cmd_result)
{
	t_token	*last_lxr;

	if (!lexer(&(*data)->lexer, line)
		&& !expander((*data), -1) && (*data)->lexer)
	{
		if (parse_lexer((*data)->lexer) != 1 && lexer_to_cmds(*data) != 1)
		{
			last_lxr = (*data)->lexer;
			while (last_lxr->right)
				last_lxr = last_lxr->right;
			update_env(*data, "_", last_lxr->str);
			*cmd_result = exec_line(*data);
		}
		else
			*cmd_result = 2;
	}
	add_history(*line);
	free(*line);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	t_datashell	*data;
	int			cmd_result;
	int			end;

	signal_parent();
	cmd_result = 0;
	data = create_minishell(env);
	if (!data)
		printf("Error\n");
	while (data->end_flag == -1)
	{
		free_lexer(&data->lexer);
		free_cmds(data);
		data->lexer = NULL;
		if (isatty(STDIN_FILENO))
			line = readline("maxi-total ⛽ > ");
		else
			line = NULL;
		if (check_process(&data, &line) == 0)
			process_exec(&data, &line, &cmd_result);
	}
	end = data->end_flag;
	(void)av[ac];
	return (free_minishell(data), end);
}
