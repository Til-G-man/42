/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:28:37 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/14 17:39:53 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	other(const char *format)
{
	int	counter;

	counter = 0;
	if (*format == '%')
	{
		write(1, "%%", 1);
		counter++;
	}
	else if (!*format)
		return (-1);
	else
	{
		write(1, "%%", 1);
		write(1, format, 1);
		counter += 2;
	}
	return (counter);
}

int	get_input(va_list args, const char *format)
{
	int	counter;

	if (*format == 'd' || *format == 'i')
		counter = ft_putnbr_fd(va_arg(args, int), 1, 0);
	else if (*format == 'u')
		counter = ft_putunbr_fd(va_arg(args, unsigned int), 1, 0);
	else if (*format == 's')
		counter = ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'p')
		counter = ft_putptr((unsigned long) va_arg(args, void *));
	else if (*format == 'x')
		counter = ft_intohex(va_arg(args, unsigned int), 0, 0);
	else if (*format == 'X')
		counter = ft_intohex(va_arg(args, unsigned int), 1, 0);
	else if (*format == 'c')
		counter = ft_putchar_fd(va_arg(args, int), 1);
	else
	{
		counter = other(format);
		if (counter < 0)
			return (-1);
	}
	return (counter);
}

int	iterate_args(va_list args, const char *format, int counter)
{
	int	wrong_input;

	while (*format)
	{
		if (*format == '%')
		{
			wrong_input = get_input(args, ++format);
			counter += wrong_input;
			if (wrong_input < 0)
				return (-1);
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			counter;
	int			worng_input;

	worng_input = 0;
	counter = 0;
	va_start(args, format);
	counter += iterate_args(args, format, counter);
	va_end(args);
	return (counter);
}
