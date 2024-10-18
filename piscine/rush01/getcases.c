/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:22:24 by norban            #+#    #+#             */
/*   Updated: 2024/07/14 10:34:28 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rush.h>
#include <ft_data.h>

int	*getcasesp(int head, int *size)
{
	if (head == 1)
	{
		*size = 1;
		return (head1);
	}
	else if (head == 2)
	{
		*size = 3;
		return (head2);
	}
	else if (head == 3)
	{
		*size = 2;
		return (head3);
	}
	else if (head == 4)
	{
		*size = 3;
		return (head4);
	}
}

int	*getcasesn(int head, int *size)
{
	if (head == -1)
	{
		*size = 1;
		return (headn1);
	}
	else if (head == -2)
	{
		*size = 3;
		return (headn2);
	}
	else if (head == -3)
	{
		*size = 2;
		return (headn3);
	}
	else if (head == -4)
	{
		*size = 3;
		return (headn4);
	}
}

int	*getcases(int head, int *size)
{
	if (head == 5)
	{
		*size = 6;
		return (head5);
	}
	if (head > 0)
		return (getcasesp(head, size));
	if (head < 0)
		return (getcasesp(head, size));
}
