/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.madrid42>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:59:39 by albmart2          #+#    #+#             */
/*   Updated: 2025/02/15 18:05:09 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;

	va_start (args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar(va_arg(args, int), 1);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[i] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'x')
				ft_putnbr_base_fd(va_arg(args, unsigned int),
					"0123456789abcdef", 1);
			else if (format[i] == 'X')
				ft_putnbr_base_fd(va_arg(args, unsigned int),
					"0123456789ABCDEF", 1);
			else if (format[i] == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_putnbr_base_fd(va_arg(args, unsigned long),
					"0123456789abcdef", 1);
			}
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
}
