/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:49:48 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/30 15:52:15 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	*ft_ptr_to_str(void *ptr, char *buffer)
{
	const char *hex_digits[];
	uintptr_t value = (uintptr_t)ptr;

	hex_digits = "0123456789abcdef";
	buffer[0] = '0';
	buffer[1] = 'x';
	for (int i = 0; i < sizeof(value) * 2; i++) {
		buffer[2 + i] = hex_digits[(value >> ((sizeof(value) * 2 - 1 - i) * 4)) & 0xf];
	}
	buffer[2 + sizeof(value) * 2] = '\0';
}
