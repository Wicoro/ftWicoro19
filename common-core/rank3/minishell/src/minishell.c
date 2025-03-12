/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:17:34 by norban            #+#    #+#             */
/*   Updated: 2025/03/12 15:58:40 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*create_minishell(char **environment)
{
	t_minishell	*minishell;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->tree = NULL;
	minishell->lexer = NULL;
	(void)environment; 
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
	while (1)
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
