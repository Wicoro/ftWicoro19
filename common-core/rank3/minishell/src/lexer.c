/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:38:27 by norban            #+#    #+#             */
/*   Updated: 2025/03/06 14:05:23 by norban           ###   ########.fr       */
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
	if (ft_strlen(s) == 1)
	{
		if (s[0] == '<' || s[0] == '>')
			lex->data_type = REDIRECTION;
		else if (s[0] == '|')
			lex->data_type = PIPE;
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
	if (line[i] == '<' || line[i] == '>' || line[i] == '|')
		return (1);
	if (!line[i + 1])
		return (1);
	if (line[i] == '\'' || line[i] == '"')
	{
		quote = line[i];
		i++;
		while (line[i] && line[i] != quote && line[i -1] != '\\')
			i++;
		return (i + 1);
	}
	i++;
	while (line[i] && line[i] != '<' && line[i] != '>'
		&& line[i] != ' ' && line[i] != '|'
		&& line[i] != '"' && line[i] != '\'')
		i++;
	return (i);
}

int	lexer(t_token **lexer, char *line)
{
	int	i;
	int	j;
	
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		j = get_next_sep(line + i);
		if (create_token(lexer, line + i, j) == 1)
			return (1);
		i += j;
	}
	return  (0);
}
