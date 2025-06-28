/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:24:46 by ydraouil          #+#    #+#             */
/*   Updated: 2025/06/14 15:27:46 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char **split_cmd, char **env)
{
	char	*command;
	char	**split_env;

	if (!env || !split_cmd || !split_cmd[0])
		return (NULL);
	if (access(split_cmd[0], X_OK) == 0)
		return (ft_strdup(split_cmd[0]));
	split_env = get_path_env(env);
	if (!split_env)
		return (NULL);
	command = get_cmd(split_cmd, split_env);
	return (free_tab(split_env), command);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int	in_out_handler(t_cmd *cmd)
{
	int	result;

	result = output_handler(cmd);
	if (result == -1)
		return (-1);
	if (input_handler(cmd) == -1)
		return (-1);
	return (0);
}

void	close_redi(t_datashell *data, int fd[2])
{
	if (!fd)
		return ;
	(void) *data;
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}
