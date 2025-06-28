/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:16:06 by norban            #+#    #+#             */
/*   Updated: 2025/06/11 19:38:00 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_pwd(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (1);
	if (getcwd(buf, 1024) != NULL)
		printf("%s\n", buf);
	else
	{
		perror("maxitotal: pwd");
		return (free(buf), 1);
	}
	return (free(buf), 0);
}
