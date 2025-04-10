/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:24:08 by norban            #+#    #+#             */
/*   Updated: 2025/02/13 16:40:20 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*test_path(char **split_cmd, char **split_env)
{
	int		j;
	char	*command;
	char	*command_pathed;

	command_pathed = ft_strjoin(split_env[0], "/");
	command = ft_strjoin(command_pathed, split_cmd[0]);
	j = 0;
	while (split_env[j] && access(command, X_OK) != 0)
	{
		j++;
		free(command_pathed);
		command_pathed = NULL;
		free(command);
		if (!split_env[j])
			break ;
		command_pathed = ft_strjoin(split_env[j], "/");
		command = ft_strjoin(command_pathed, split_cmd[0]);
	}
	if (!split_env[j])
		command = NULL;
	free(command_pathed);
	return (command);
}

char	*get_command(char *av, char **env)
{
	char	**split_cmd;
	char	**split_env;
	char	*command;
	int		i;

	if (av[0] && av[0] == '/' && access(av, X_OK) == 0)
		return (ft_strdup(av));
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	split_cmd = ft_split(av, ' ');
	if (!env[i] || !split_cmd[0])
		return (print_error(4), NULL);
	split_env = ft_split(env[i] + 5, ':');
	command = test_path(split_cmd, split_env);
	free_split(split_cmd);
	free_split(split_env);
	return (command);
}

int	is_args_valid(int ac, char **av)
{
	int	fd;

	if (ac != 5 || ft_strlen(av[2]) == 0 || ft_strlen(av[3]) == 0)
		return (print_error(0), 0);
	if (access(av[1], R_OK) != 0)
		return (print_error(1), 0);
	fd = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644644);
	if (fd != -1 && access(av[4], W_OK) != 0)
		return (print_error(1), 0);
	close(fd);
	return (1);
}
