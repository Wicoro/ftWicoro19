/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_to_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:10:28 by norban            #+#    #+#             */
/*   Updated: 2025/04/10 13:35:04 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*concat_cmd_str(t_token *node)
{
	t_token	*crt;
	char	*new_str;
	char	*tmp_str;
	char	*tmp_str2;
	
	crt = node;
	new_str = ft_strdup("");
	if (!new_str)
		return (NULL);
	while (crt && crt->data_type != PIPE)
	{
		if (crt->data_type == WORD && (!crt->left || crt->left->data_type != REDIRECTION))
		{
			tmp_str2 = ft_strjoin(new_str, " ");
			free(new_str);
			tmp_str = ft_strjoin(tmp_str2, crt->str);
			free(tmp_str2);
			new_str = tmp_str;
		}
		crt = crt->right;
	}
	return (new_str);
}

int	get_redirection(t_token *ref_node, int *red_id, char **red_file)
{
	t_token	*crt;
	int		i;

	crt = ref_node;
	i = 0;
	while (crt && crt->data_type != PIPE)
	{
		if (crt->data_type == REDIRECTION)
		{
			if (ft_strncmp(crt->str, "<<", 3) == 0)
				red_id[i] = 1;
			if (ft_strncmp(crt->str, ">>", 3) == 0)
				red_id[i] = 2;
			if (ft_strncmp(crt->str, "<", 2) == 0)
				red_id[i] = 3;
			if (ft_strncmp(crt->str, ">", 2) == 0)
				red_id[i] = 4;
			red_file[i] = ft_strdup(crt->right->str);
			if (!red_file[i])
				return (1);
			i++;
		}
		crt = crt->right;
	}
	return (0);
}

int	get_red_count(t_token *ref_node)
{
	t_token	*crt;
	int		count;
	
	crt = ref_node;
	count = 0;
	while (crt && crt->data_type != PIPE)
	{
		if (crt->data_type == REDIRECTION)
			count++;
		crt = crt->right;
	}
	return (count);
}

t_cmd	*create_cmd(t_token *crt)
{
	t_cmd	*cmd;
	int		red_count;
	
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->next = NULL;
	cmd->str = concat_cmd_str(crt);
	red_count = get_red_count(crt);
	cmd->red_id = malloc(sizeof(int) * (red_count + 1));
	if (!cmd->red_id)
		return (free(cmd), NULL);
	cmd->red_file = malloc(sizeof(char *) * (red_count + 1));
	if (!cmd->red_file)
		return (free(cmd), free(cmd->red_id), NULL);
	cmd->red_id[red_count] = 0;
	cmd->red_file[red_count] = NULL;
	if (get_redirection(crt, cmd->red_id, cmd->red_file) == 1)
		return (free(cmd), free(cmd->red_id), free(cmd->red_file), NULL);
	return (cmd);
}

int	lexer_to_cmds(t_datashell *data)
{
	t_token	*crt_node;
	t_cmd	*crt_cmd;
	
	crt_node = data->lexer;
	data->cmd_list = create_cmd(crt_node);
	if (!data->cmd_list)
		return (1);
	crt_cmd = data->cmd_list;
	while (crt_node)
	{
		while (crt_node && crt_node->data_type != PIPE)
			crt_node = crt_node->right;
		if (crt_node && crt_node->data_type == PIPE)
		{
			crt_node = crt_node->right;
			crt_cmd->next = create_cmd(crt_node);
			if (!crt_cmd->next)
				return (free_cmds(data), 1);
			crt_cmd = crt_cmd->next;
		}
	}
	return (0);
}
