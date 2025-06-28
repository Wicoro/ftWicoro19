/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 02:41:19 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 15:54:42 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirection(t_token *crt, t_cmd *cmd)
{
	int	red_count;

	red_count = get_red_count(crt);
	cmd->red_id = malloc(sizeof(int) * (red_count + 1));
	if (!cmd->red_id)
		return (-1);
	cmd->red_file = malloc(sizeof(char *) * (red_count + 1));
	if (!cmd->red_file)
	{
		free(cmd->red_id);
		return (-1);
	}
	cmd->red_id[red_count] = 0;
	cmd->red_file[red_count] = NULL;
	if (get_redirection(crt, cmd->red_id, cmd->red_file) == 1)
	{
		free_tab(cmd->red_file);
		free(cmd->red_id);
		return (-1);
	}
	return (0);
}

t_cmd	*initialize_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->next = NULL;
	cmd->hd_pipe = NULL;
	return (cmd);
}

t_cmd	*fill_cmd(t_token *crt, t_cmd *cmd, t_datashell *data)
{
	if (fill_cmd_tab(crt, cmd->cmd_tab) == -1)
		return (free(cmd->cmd_tab), free(cmd), NULL);
	if (handle_redirection(crt, cmd) == -1)
		return (free_tab(cmd->cmd_tab), free(cmd->cmd_tab), free(cmd), NULL);
	if (process_heredoc(cmd, data) == 1)
		return (free_cmd(cmd), NULL);
	return (cmd);
}

t_cmd	*create_cmd(t_token *crt, t_datashell *data)
{
	t_cmd	*cmd;
	int		cmd_len;
	t_token	*temp;

	cmd = initialize_cmd();
	if (!cmd)
		return (NULL);
	cmd_len = 0;
	temp = crt;
	while (temp && temp->data_type != PIPE)
	{
		if (temp->data_type == WORD
			&& (!temp->left || temp->left->data_type != REDIRECTION))
			cmd_len++;
		temp = temp->right;
	}
	cmd->cmd_tab = allocate_cmd_tab(cmd_len);
	if (!cmd->cmd_tab)
		return (free(cmd), NULL);
	cmd = fill_cmd(crt, cmd, data);
	return (cmd);
}
