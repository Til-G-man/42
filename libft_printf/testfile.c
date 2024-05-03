/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:09:27 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/03 14:49:16 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
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


//int ft_printf(const char *format, ...) {
//    va_list args;
//    va_start(args, format);

//    while (*format) { // Durchlaufe den Formatierungsstring
//        if (*format == '%') { // Wenn ein Formatzeichen gefunden wird
//            format++; // Gehe zum Typspezifikator
//            switch (*format) {
//                case 'd': { // Integer
//                    int i = va_arg(args, int);
//                    printf("%d", i);
//                    break;
//                }
//                case 's': { // String
//                    char *s = va_arg(args, char*);
//                    printf("%s", s);
//                    break;
//                }
//                // Fügen Sie hier weitere Fälle für andere Typen hinzu
//            }
//        } else {
//            putchar(*format); // Drucke das Zeichen, wenn es kein Formatzeichen ist
//        }
//        format++; // Gehe zum nächsten Zeichen
//    }

//    va_end(args);
//    return 0;
//}


//void	ft_putptr(unsigned long num)
//{
//	char *hex_digits = "0123456789abcdef";
//	char buffer[20];
//	int i = 0;

//	while (num)
//	{
//		buffer[i++] = hex_digits[num % 16];
//		num = num / 16;
//	}
//	write(1, "0x", 2);
//	while (--i >= 0)
//		write(1, &buffer[i], 1);
//}


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
				printf("%% sign %x is of type unsigned int (x)\n", va_arg(args, unsigned int));
			else if (*format == 'X')
				printf("%% sign %X is of type unsigned int (X)\n", va_arg(args, unsigned int));
			else if (*format == '%')
				write(output, "%%", 1);
		}
		else
			write(1, format, 1);
		format++;
	}
	return (0);
}

int	main(void)
{
ft_printf("first decimal (d): %d\nstring (s): %s\n%% (%%): %%\n", 42, "hallo");
printf("printf pointer: %p\n", &"HAllo");
ft_printf("ft_printf pointer: %p\nand ft_ptint f string: %s \n", &"HAllo", "Hallo Welt");
//ft_printf("string (s): %s\n", "hello");
//ft_printf("pointer (p): %p\n", (void*)&main);
//ft_printf("int (i): %i\n", 42);
//ft_printf("unsigned int (u): %u\n", 42);
//ft_printf("hex lowercase (x): %x\n", 42);
//ft_printf("hex uppercase (X): %X\n", 42);
//ft_printf("percent sign (%%): %%\n");
}
