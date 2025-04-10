/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:38:27 by norban            #+#    #+#             */
/*   Updated: 2025/03/28 14:59:14 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_to_lexer(t_token **lexer, t_token *lex)
{
	t_token	*crt;

	crt = *lexer;
	while (crt && crt->right)
		crt = crt->right;
	if (!crt)
	{
		*lexer = lex;
		lex->left = 0;
	}
	else
	{
		crt->right = lex;
		lex->left = crt;
	}
	lex->right = 0;
}

int	create_token(t_token **lexer, char *src, int len)
{
	char	*s;
	t_token	*lex;
	
	s = ft_substr(src, 0, len);
	if (!s)
		return (1);
	lex = malloc(sizeof(t_token));
	if (!lex)
		return (free(s), 1);
	lex->data_type = WORD;
	if (ft_strlen(s) == 1 || ft_strlen(s) == 2)
	{
		if (ft_strlen(s) == 1 && (s[0] == '<' || s[0] == '>'))
			lex->data_type = REDIRECTION;
		else if (ft_strlen(s) == 1 && s[0] == '|')
			lex->data_type = PIPE;
		else if (ft_strlen(s) == 2
			&& ((s[0] == '<' && s[1] == '<')
			|| (s[0] == '>' && s[1] == '>')))
			lex->data_type = REDIRECTION;
	}
	lex->str = s;
	add_to_lexer(lexer, lex);
	return (0);
}

int	get_next_sep(char *line)
{
	int		i;
	char	quote;

	i = 0;
	if (line[i] && line[i + 1] 
		&& ((line[i] == '<' && line[i + 1] == '<')
		|| ((line[i] == '>') && line[i + 1] == '>')))
		return (2);
	if (line[i] == '<' || line[i] == '>' || line[i] == '|')
		return (1);
	while (line[i] && line[i] != '<' && line[i] != '>'
		&& line[i] != ' ' && line[i] != '|')
	{
		if ((line[i] == '\'' || line[i] == '"') && !line[i + 1])
			return (-1);
		if (line[i] && !line[i + 1])
			return (i + 1);
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i];
			i++;
			while (line[i] && line[i] != quote && line[i -1] != '\\')
				i++;
			if (!line[i])
				return (-1);
		}
		i++;
	}
	return (i);
}

int	lexer(t_token **lexer, char *line)
{
	int	i;
	int	j;
	
	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		j = get_next_sep(line + i);
		if (j == -1)
			return (printf("quote not ended properly\n"), 1);
		if (create_token(lexer, line + i, j) == 1)
			return (printf("malloc error\n"), free(line), 1);
		i += j;
	}
	return  (0);
}
