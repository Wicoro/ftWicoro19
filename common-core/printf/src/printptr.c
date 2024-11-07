/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:51:37 by norban            #+#    #+#             */
/*   Updated: 2024/11/07 11:31:46 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printuptr_base(char *base, size_t l, int len)
{
	int	tmp;

	if (l >= 16)
	{
		tmp = printuptr_base(base, l / 16, len);
		if (tmp == -1)
			return (-1);
		len = tmp;
		tmp = printuptr_base(base, l % 16, len);
		if (tmp == -1)
			return (-1);
		len = tmp;
	}
	else
	{
		if (printchar(base[l]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	printptr_base(size_t l, char *base)
{
	int				len;
	int				tmp;

	len = 0;
	tmp = printuptr_base(base, l, len);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	printptr(void *ptr)
{
	int		len;
	size_t	l_ptr;

	if (!ptr)
		return (printstr("0x0"));
	l_ptr = (size_t)ptr;
	len = printstr("0x");
	if (len == -1)
		return (-1);
	len = printptr_base(l_ptr, "0123456789abcdef");
	if (len == -1)
		return (-1);
	return (len + 2);
}

/*#include <stdio.h>
int main()
{
	printf("\n%d\n", printptr(""));
}*/
