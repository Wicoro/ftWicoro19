/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:17:34 by norban            #+#    #+#             */
/*   Updated: 2025/04/16 16:39:05 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_datashell	*create_minishell(char **environment)
{
	t_datashell	*data;
	int			i;

	i = 0;
	data = malloc(sizeof(t_datashell));
	if (!data)
		return (NULL);
	data->cmd_list = NULL;
	data->lexer = NULL;
	if (env_to_llist(environment, data) == 1)
		return (free(data), NULL);
	return (data);
}

void	print_lexer(t_token **lexer)
{
	t_token *crt;
	crt = *lexer;
	printf("\nLexer : \n");
	while (crt)
	{
		printf("%s -> ", crt->str);
		crt = crt->right;
	}
	printf("\n");
	printf("\n");
}

void	print_cmds(t_cmd *cmd)
{
	t_cmd	*crt;
	int		i;
	
	crt = cmd;
	printf("Cmd llist :\n");
	while (crt)
	{
		printf("String command : %s\nRedirection arrays\n", crt->str);
		i = 0;
		while (crt->red_id[i] != 0)
		{
			printf("red ID : %d -> red file : %s\n", crt->red_id[i], crt->red_file[i]);
			i++;
		}
		if (i == 0)
			printf("no redirection\n");
		printf("\n");
		crt = crt->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	t_datashell	*data;
	int			cmd_result;

	cmd_result = 0;
	signal_handler();
	data = create_minishell(env);
	if (!data)
		printf("error\n");
		//print_error(0);
	while (data)
	{
		free_lexer(&data->lexer);
		data->lexer = NULL;
		line = readline("maxi-total ⛽ > ");
		if (line && ft_strlen(line) == 0)
			free(line);
		else if (!line || ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			free_minishell(data);
			data = NULL;
		}
		else if (ft_strncmp(line, "$?", 2) == 0)
			printf("%d\n", cmd_result);
		else
		{
			if (lexer(&data->lexer, &line))
			{
				free(line);
				free_lexer(&data->lexer);
				exit(1);
			}
			else
			{
				expander(data->lexer, data->env_start);
				if (parse_lexer(data->lexer) != 1)
				{
					lexer_to_cmds(data);
					print_lexer(&data->lexer);
					print_cmds(data->cmd_list);
				}
			}
			free(line);
		}
	}
	free_minishell(data);
	(void)ac;
	(void)av;
	return (0);
}
