/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.S19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:24:04 by norban            #+#    #+#             */
/*   Updated: 2024/11/07 09:40:15 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	printchar(int c);
int	printstr(char *str);
int	printptr(void *ptr);
int	printnbr_base(int nb, char *base);
int	printnbr(int nb);
int	printunbr(unsigned int nb);
int	ft_printf(const char *str, ...);

#endif
