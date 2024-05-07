/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:09:27 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/07 18:12:16 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			counter;

	counter = 0;
	va_start(args, format);
	while (*format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 'd' || *format == 'i'
				|| *format == 'u')
				counter += ft_putnbr_fd(va_arg(args, int), 1, 0);
			else if (*format == 's')
				counter += ft_putstr_fd(va_arg(args, char *), 1);
			else if (*format == 'p')
				counter += ft_putptr((unsigned long) va_arg(args, void *));
			else if (*format == 'x' || *format == 'X')
				counter += ft_intohex(va_arg(args, unsigned int), 0, 0);
			else if (*format == '%')
			{
				write(1, "%%", 1);
				counter++;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
	}
	return (counter);
}
