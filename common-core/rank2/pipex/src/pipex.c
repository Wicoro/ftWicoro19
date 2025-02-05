/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:26:27 by norban            #+#    #+#             */
/*   Updated: 2025/01/31 17:27:02 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *av, char **env)
{
	char	*shell_command;
	char	**shell_command_args;

	shell_command = get_command(av, env);
	shell_command_args = ft_split(av, ' ');
	if (execve(shell_command, shell_command_args, env) == -1)
	{
		free(shell_command);
		free_split(shell_command_args);
		print_error(2);
	}
}

void	process_parent(int *pipe_fd, char **av, char **env)
{
	int	fd;

	fd = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644644);
	if (fd == -1)
		print_error(3);
	dup2(fd, STD_OUT);
	dup2(pipe_fd[0], STD_IN);
	if (close(pipe_fd[1]) || close(pipe_fd[0]) || close(fd))
		print_error(5);
	exec(av[3], env);
}

void	process_child(int *pipe_fd, char **av, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error(3);
	dup2(fd, STD_IN);
	dup2(pipe_fd[1], STD_OUT);
	if (close(pipe_fd[1]) || close(pipe_fd[0]) || close(fd))
		print_error(5);
	exec(av[2], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (is_args_valid(ac, av) == 0)
		return (0);
	if (pipe(pipe_fd) == -1)
		return (print_error(-1), 0);
	pid = fork();
	if (pid == -1)
		return (print_error(-1), 0);
	if (pid == 0)
		process_child(pipe_fd, av, env);
	pid2 = fork();
	if (pid2 == -1)
		return (print_error(-1), 0);
	if (pid2 == 0)
		process_parent(pipe_fd, av, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid, 0, 0);
	waitpid(pid2, 0, 0);
}
