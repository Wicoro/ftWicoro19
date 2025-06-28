/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:43:26 by norban            #+#    #+#             */
/*   Updated: 2025/06/13 20:18:29 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	squote_expander(char **str, int trim_start)
{
	int		i;
	char	*tmp_str;
	char	*tmp_str2;

	i = trim_start;
	tmp_str = ft_strnreplace(*str, "'", "", trim_start);
	if (!tmp_str)
		return (1);
	while (tmp_str[i])
	{
		if (tmp_str[i] == '\'')
		{
			tmp_str2 = ft_strnreplace(tmp_str, "'", "", i);
			if (!tmp_str2)
				return (1);
			free(*str);
			free(tmp_str);
			*str = tmp_str2;
			return (i - 1 - trim_start);
		}
		i++;
	}
	return (i - 1 - trim_start);
}

static int	dquote_expander(char **str, int trim_start, t_datashell *data)
{
	int		len;
	char	*tmp_str;
	char	*quoted_str;
	char	*inter_quoted_str;
	char	*i_quoted_str_t;

	quoted_str = ft_substr(*str, trim_start,
			ft_strchr(*str + trim_start + 1, '"') - (*str + trim_start) + 1);
	if (!quoted_str)
		return (1);
	inter_quoted_str = loop_var_exchanger(quoted_str, data);
	if (!inter_quoted_str)
		return (1);
	i_quoted_str_t = ft_strtrim(inter_quoted_str, "\"");
	if (!i_quoted_str_t)
		return (1);
	tmp_str = ft_strnreplace(*str, quoted_str, i_quoted_str_t, trim_start);
	if (!(tmp_str))
		return (1);
	free(*str);
	*str = tmp_str;
	free(quoted_str);
	free(inter_quoted_str);
	len = ft_strlen(i_quoted_str_t) - 1;
	return (free(i_quoted_str_t), len);
}

int	check_empty_expander(t_token *crt, int *i, t_datashell *data)
{
	if (crt->str[*i] == '$' && crt->str[(*i) + 1] && crt->str[(*i) + 1] != '$'
		&& ((crt->left && ft_strncmp(crt->left->str, "<<", 3) != 0)
			|| !crt->left)
		&& (ft_isprint(crt->str[*i + 1]) && crt->str[*i] != '"'))
	{
		if (exchanger(&crt->str, *i,
				data->env_start, data->return_val) != 0)
			return (1);
		else
			(*i)--;
	}
	return (0);
}

void	remove_token(t_token **crt, t_datashell **data)
{
	t_token	*next;

	next = (*crt)->right;
	if ((*data)->lexer == (*crt))
		(*data)->lexer = (*crt)->right;
	if ((*crt)->left)
		(*crt)->left->right = (*crt)->right;
	if ((*crt)->right)
		(*crt)->right->left = (*crt)->left;
	free((*crt)->str);
	free((*crt));
	(*crt) = next;
}

int	expander(t_datashell *data, int i)
{
	t_token	*crt;
	char	*r;

	crt = data->lexer;
	while (crt)
	{
		r = ft_strdup(crt->str);
		i = -1;
		while (crt->str && crt->str[++i])
		{
			if (crt->str[i] == '\'')
				i += squote_expander(&crt->str, i);
			else if (crt->str[i] == '"'
				&& ft_strncmp(crt->left->str, "<<", 3) != 0)
				i += dquote_expander(&crt->str, i, data);
			else if (check_empty_expander(crt, &i, data) == 1)
				return (free(r), 1);
		}
		if (ft_strncmp(crt->str, r, 21474836) != 0 && ft_strlen(crt->str) == 0)
			remove_token(&crt, &data);
		else
			crt = crt->right;
		free(r);
	}
	return (0);
}
