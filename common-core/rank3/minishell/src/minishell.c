/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:17:34 by norban            #+#    #+#             */
/*   Updated: 2025/03/06 15:28:34 by norban           ###   ########.fr       */
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

void	print_lexer(t_token *lexer)
{
	while (lexer)
	{
		printf("%s, %d\n", lexer->str, lexer->data_type);
		lexer = lexer->right;
	}
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
		free_lexer(&minishell->lexer);
		line = readline("maxi-total ⛽ > ");
		if (ft_strncmp(line, "$?", 2) == 0)
			printf("%d\n", cmd_result);
		else if (lexer(&minishell->lexer, line) == 1)
		{
			free(line);
			printf("malloc error\n");
		}
		free(line);
		if (parse_lexer(minishell) != 1)
			process_lexer_to_tree(minishell);
		print_lexer(minishell->lexer);
	}
	(void)ac;
	(void)av;
	return (0);
}
