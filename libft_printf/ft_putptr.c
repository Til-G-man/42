/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:17:02 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/03 14:49:17 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putptr(unsigned long num)
{
	char *hex_digits = "0123456789abcdef";
	char buffer[20];
	int i = 0;

	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num = num / 16;
	}
	write(1, "0x", 2);
	while (--i >= 0)
		write(1, &buffer[i], 1);
}
