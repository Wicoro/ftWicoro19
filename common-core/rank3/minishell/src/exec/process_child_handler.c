/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:25:22 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 15:21:22 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	end_p_child(int **p_tab, char **cmd_tab, char **env)
{
	if (cmd_tab && cmd_tab[0])
		ft_putstr_fd("Error : Command not found\n", 2);
	close_fd(p_tab);
	free_itab(p_tab);
	free_tab(cmd_tab);
	free_tab(env);
	exit(127);
}

static int	close_hd_do_builtin(t_datashell *data, char **cmd_tab, t_cmd *cmd)
{
	close_hd(data->cmd_list->hd_pipe);
	if (check_builtin(data, cmd_tab, cmd) == 1)
		return (0);
	return (1);
}

int	exec_child(char *path, t_cmd *cmd, int **p_tab, t_datashell *data)
{
	char	**env;
	char	**cmd_tab;

	cmd_tab = cmd->cmd_tab;
	env = get_full_env(data->env_start);
	if (!env)
		return (-1);
	if (execve(path, cmd_tab, env) == -1)
		return (close_hd(cmd->hd_pipe), ffree(cmd_tab, p_tab, env, path), -1);
	return (0);
}

int	p_child(int **p_tab, t_cmd *cmd, int i, t_datashell *data)
{
	char	**cmd_tab;
	char	*path;
	char	**env;

	signal_child();
	cmd_tab = cmd->cmd_tab;
	if (!cmd_tab)
		return (-1);
	if (i != 0)
		dup2(p_tab[i - 1][0], STDIN_FILENO);
	if (p_tab[i])
		dup2(p_tab[i][1], STDOUT_FILENO);
	close_fd(p_tab);
	if (cmd->red_id[0] && call_handler(cmd) == -1)
		return (free_itab(p_tab),
			close_hd_do_builtin(data, cmd_tab, cmd), free_tab(cmd_tab), -1);
	if (close_hd_do_builtin(data, cmd_tab, cmd) == 0)
		return (-1);
	env = get_full_env(data->env_start);
	if (!env)
		return (free_itab(p_tab), free_tab(cmd_tab), -1);
	path = get_path(cmd_tab, env);
	if (!path)
		return (end_p_child(p_tab, cmd_tab, env));
	return (free(env), exec_child(path, cmd, p_tab, data));
}
