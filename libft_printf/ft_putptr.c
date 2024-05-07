/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:28:07 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/07 18:11:16 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long num)
{
	char	*hex_digits;
	char	buffer[20];
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	hex_digits = "0123456789abcdef";
	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num = num / 16;
	}
	write(1, "0x", 2);
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		counter++;
	}
	return (counter);
}
