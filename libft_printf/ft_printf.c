/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:09:27 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/04 15:17:26 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
//possible d-types: cspdiuxX%
//c: Character
//	Kürzel: c
//	Beispiel: ft_printf("%c", 'A'); // Ausgabe: A
//s: String
//	Kürzel: s
//	Beispiel: ft_printf("%s", "Hello, World!"); // Ausgabe: Hello, World!
//p: Pointer (Adresse)
//	Kürzel: p
//	Beispiel: ft_printf("%p", &variable); // Ausgabe: 0x7ffdeea33320 (Beispieladresse)
//d: Signed Decimal Integer
//	Kürzel: d
//	Beispiel: ft_printf("%d", -42); // Ausgabe: -42
//i: Signed Decimal Integer (identisch zu d)
//	Kürzel: i
//	Beispiel: ft_printf("%i", 42); // Ausgabe: 42
//u: Unsigned Decimal Integer
//	Kürzel: u
//	Beispiel: ft_printf("%u", 42); // Ausgabe: 42
//x: Unsigned Hexadecimal Integer (kleinbuchstaben)
//	Kürzel: x
//	Beispiel: ft_printf("%x", 255); // Ausgabe: ff
//X: Unsigned Hexadecimal Integer (Großbuchstaben)
//	Kürzel: X
//	Beispiel: ft_printf("%X", 255); // Ausgabe: FF
//%: Prozentzeichen
//	Kürzel: %%
//	Beispiel: ft_printf("%%"); // Ausgabe: %


int	ft_printf(const char *format, ...)
{
	va_list		args;
	va_start(args, format);
	int	output;

	output = 1;
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putnbr_fd(va_arg(args, int), output);
			else if (*format == 's')
				ft_putstr_fd(va_arg(args, char *), output);
			else if (*format == 'p')
				ft_putptr((unsigned long) va_arg(args, void *));
			else if (*format == 'd')
				ft_putnbr_fd(va_arg(args, int), output);
			else if (*format == 'i')
				ft_putnbr_fd(va_arg(args, int), output);
			else if (*format == 'u')
				ft_putnbr_fd((unsigned) va_arg(args, int), output);
			else if (*format == 'x')
			{
				ft_intohex(va_arg(args, unsigned int), 0);
			}
			else if (*format == 'X')
				ft_intohex(va_arg(args, unsigned int), 1);
			else if (*format == '%')
				write(output, "%%", 1);
		}
		else
			write(1, format, 1);
		format++;
	}
	return (0);
}
