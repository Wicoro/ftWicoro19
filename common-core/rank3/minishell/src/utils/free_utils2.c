/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:07:42 by norban            #+#    #+#             */
/*   Updated: 2025/06/14 16:00:13 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	free(cmd->red_id);
	free_tab(cmd->cmd_tab);
	free_tab(cmd->red_file);
	close_hd(cmd->hd_pipe);
	free(cmd);
	cmd = NULL;
}

void	free_exit(t_cmd *cmd, t_datashell *data, char *f, int n)
{
	free_cmd(cmd);
	free_minishell(data);
	free(f);
	exit(n);
}
