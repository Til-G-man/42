/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:28:07 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/18 12:50:26 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fck25lines(unsigned long num)
{
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (1);
	}
	return (0);
}

int	ft_putptr_count(unsigned long num)
{
	char	*hex_digits;
	char	buffer[20];
	int		i;
	int		counter;

	if (fck25lines(num))
		return (5);
	i = 0;
	counter = 0;
	hex_digits = "0123456789abcdef";
	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num = num / 16;
	}
	write(1, "0x", 2);
	counter += 2;
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		counter++;
	}
	return (counter);
}
