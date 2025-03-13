/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:17:34 by norban            #+#    #+#             */
/*   Updated: 2025/03/13 14:40:58 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*extract_env(char *str)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->next = NULL;
	env->prev = NULL;
	env->str = str;
	return (env);
}

int	env_to_llist(char **environment, t_minishell *minishell)
{
	int		i;
	t_env	*crt;
	if (!environment || !environment[0])
		return (0);
	i = 0;
	minishell->env_start = extract_env(environment[i]);
	if (!minishell->env_start)
		return (1);
	i++;
	crt = minishell->env_start;
	while (environment[i])
	{
		crt->next = extract_env(environment[i]);
		if (!crt->next)
			return (1);
		i++;
		crt = crt->next;
	}
	return (0);
}

t_minishell	*create_minishell(char **environment)
{
	t_minishell	*minishell;
	int			i;

	i = 0;
	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->tree = NULL;
	minishell->lexer = NULL;
	if (env_to_llist(environment, minishell) == 1)
		return (free(minishell), NULL);
	return (minishell);
}

void	print_lexer(t_token **lexer)
{
	t_token *crt;
	crt = *lexer;
	while (crt)
	{
		printf("%s -> ", crt->str);
		crt = crt->right;
	}
	printf("\n");
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	t_minishell	*minishell;
	int			cmd_result;

	cmd_result = 0;
	minishell = create_minishell(env);
	if (!minishell)
		printf("error\n");
		//print_error(0);
	while (minishell)
	{
		free_tree(&minishell->tree);
		minishell->lexer = NULL;
		line = readline("maxi-total ⛽ > ");
		if (ft_strlen(line) == 0)
			free(line);
		else if (ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			break;
		}
		else if (ft_strncmp(line, "$?", 2) == 0)
			printf("%d\n", cmd_result);
		else
		{
			if (lexer(&minishell->lexer, ft_strtrim(line, " ")) == 1)
			{
				free(line);
				free_lexer(&minishell->tree);
				printf("malloc error\n");
				exit(1);
			}
			else
			{
				print_lexer(&minishell->lexer);
				if (parse_lexer(minishell) != 1)
					process_lexer_to_tree(minishell);
			}
			free(line);
		}
	}
	free_tree(&minishell->tree);
	free_minishell(minishell);
	(void)ac;
	(void)av;
	return (0);
}
