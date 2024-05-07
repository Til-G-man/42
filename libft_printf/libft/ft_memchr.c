/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:22:29 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/26 14:25:42 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				counter;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (*(str + counter) == (unsigned char)c)
			return ((void *)(str + counter));
		counter++;
	}
	return (NULL);
}
