/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:09:27 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/29 23:07:44 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

//possible d-types: cspdiuxX%
int	ft_printf(const char *format, ...)
{
	char	**str;
	int		str_iterator;

	str_iterator = 0;
	str = ft_split(format, '%');
	while (str[str_iterator])
	{
		if (str[str_iterator][0] == 'c')
			printf("%% sign %d is of type char (c)", str_iterator);
		if (str[str_iterator][0] == 's')
			printf("%% sign %d is of type string (s)", str_iterator);
		if (str[str_iterator][0] == 'p')
		    printf("%% sign %d is of type pointer (p)", str_iterator);
		if (str[str_iterator][0] == 'd')
		    printf("%% sign %d is of type int (d)", str_iterator);
		if (str[str_iterator][0] == 'i')
		    printf("%% sign %d is of type int (i)", str_iterator);
		if (str[str_iterator][0] == 'u')
		    printf("%% sign %d is of type unsigned int (u)", str_iterator);
		if (str[str_iterator][0] == 'x')
		    printf("%% sign %d is of type unsigned int (x)", str_iterator);
		if (str[str_iterator][0] == 'X')
		    printf("%% sign %d is of type unsigned int (X)", str_iterator);
		if (str[str_iterator][0] == '%')
		    printf("%% sign %d is of type char (%%)", str_iterator);

	}
	return (0);
}

int	main(void)
{
ft_printf("first decimal (d): %d\n", 42);
ft_printf("string (s): %s\n", "hello");
ft_printf("pointer (p): %p\n", (void*)&main);
ft_printf("int (i): %i\n", 42);
ft_printf("unsigned int (u): %u\n", 42);
ft_printf("hex lowercase (x): %x\n", 42);
ft_printf("hex uppercase (X): %X\n", 42);
ft_printf("percent sign (%%): %%\n");
}
