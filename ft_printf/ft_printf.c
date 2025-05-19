/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmart2 <albmart2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:59:39 by albmart2          #+#    #+#             */
/*   Updated: 2025/02/17 11:53:45 by albmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_format(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 'd')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'x')
		count += ft_putnbr_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	else if (specifier == 'X')
		count += ft_putnbr_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	else if (specifier == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putnbr_base_fd(va_arg(args, unsigned long),
				"0123456789abcdef", 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_format(args, format[i]);
			i++;
		}
		else
		{
			count += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
