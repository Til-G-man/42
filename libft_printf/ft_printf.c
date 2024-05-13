/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:28:37 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/13 15:42:40 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_input(va_list args, const char *format)
{
	int counter;

	counter = 0;
	if (*format == 'd' || *format == 'u' || *format == 'i')
		counter += ft_putnbr_fd(va_arg(args, int), 1, 0);
	else if (*format == 's')
		counter += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'p')
		counter += ft_putptr((unsigned long) va_arg(args, void *));
	else if (*format == 'x')
		counter += ft_intohex(va_arg(args, unsigned int), 0, 0);
	else if (*format == 'X')
		counter += ft_intohex(va_arg(args, unsigned int), 1, 0);
	else if (*format == 'c')
		counter += ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == '%')//check again %%%
	{
		write(1, "%%", 1);
		counter++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += get_input(args, format);
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}
