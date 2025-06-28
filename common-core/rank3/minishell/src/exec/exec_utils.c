/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:01:34 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/13 19:56:31 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_env(char **env)
{
	int		i;
	char	**split_env;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (!env[i])
		return (NULL);
	split_env = ft_split(env[i] + 5, ':');
	if (!split_env)
		return (NULL);
	return (split_env);
}

char	*get_cmd(char **split_cmd, char **split_env)
{
	int		j;
	char	*command;
	char	*command_pathed;

	command_pathed = ft_strjoin(split_env[0], "/");
	if (!command_pathed)
		return (NULL);
	command = ft_strjoin(command_pathed, split_cmd[0]);
	if (!command)
		return (free(command_pathed), NULL);
	j = 0;
	while (split_env[j] && access(command, X_OK) != 0)
	{
		j++;
		free(command_pathed);
		free(command);
		command_pathed = NULL;
		command = NULL;
		if (!split_env[j])
			return (NULL);
		command_pathed = ft_strjoin(split_env[j], "/");
		command = ft_strjoin(command_pathed, split_cmd[0]);
	}
	free(command_pathed);
	return (command);
}

static int	do_builtin2(char **split_cmd, t_datashell *data, t_cmd *cmd)
{
	if (ft_strncmp(split_cmd[0], "unset", 6) == 0)
	{
		in_out_handler(cmd);
		data->return_val = bi_unset(split_cmd, data);
		return (0);
	}
	if (ft_strncmp(split_cmd[0], "env", 4) == 0)
	{
		in_out_handler(cmd);
		data->return_val = bi_env(data);
		return (0);
	}
	if (ft_strncmp(split_cmd[0], "export", 7) == 0)
	{
		in_out_handler(cmd);
		data->return_val = bi_export(split_cmd, data);
		return (0);
	}
	if (ft_strncmp(split_cmd[0], "exit", 5) == 0)
	{
		bi_exit(data, split_cmd);
		return (0);
	}
	return (-1);
}

int	do_builtin(char **split_cmd, t_datashell *data, t_cmd *cmd)
{
	if (!split_cmd || !split_cmd[0])
		return (-1);
	if (ft_strncmp(split_cmd[0], "echo", 5) == 0)
	{
		in_out_handler(cmd);
		data->return_val = bi_echo(split_cmd);
		return (0);
	}
	if (ft_strncmp(split_cmd[0], "cd", 3) == 0)
	{
		in_out_handler(cmd);
		data->return_val = bi_cd(split_cmd, data->env_start);
		return (0);
	}
	if (ft_strncmp(split_cmd[0], "pwd", 4) == 0)
	{
		in_out_handler(cmd);
		data->return_val = bi_pwd();
		return (0);
	}
	return (do_builtin2(split_cmd, data, cmd));
}
