/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:10:25 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/30 13:31:01 by tgluckli         ###   ########.fr       */
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
			printf("%% sign %d is of type char (c)", va_arg(args, char*));
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
