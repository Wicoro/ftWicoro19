/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:09:05 by norban            #+#    #+#             */
/*   Updated: 2024/11/07 11:42:33 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	type_sort(va_list args, char type)
{
	if (type == '%')
		return (printchar('%'));
	else if (type == 'x')
		return (printnbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (type == 'X')
		return (printnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (type == 'c')
		return (printchar(va_arg(args, int)));
	else if (type == 's')
		return (printstr(va_arg(args, char *)));
	else if (type == 'p')
		return (printptr(va_arg(args, void *)));
	else if (type == 'u')
		return (printunbr(va_arg(args, int)));
	else
		return (printnbr(va_arg(args, int)));
}

int	process_len(int *len, int tmp)
{
	if (tmp == -1)
		return (-1);
	*len += tmp;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		tmp;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			tmp = type_sort(args, *(str + 1));
			if (process_len(&len, tmp) == -1)
				return (-1);
			str += 2;
		}
		else
		{
			tmp = printchar(*str);
			if (process_len(&len, tmp) == -1)
				return (-1);
			str++;
		}
	}
	return (len);
}

/*int main()
{
	return (0);
}*/
