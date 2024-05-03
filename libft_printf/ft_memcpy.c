/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:06:53 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/03 17:05:00 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			count;

	if (n == 0)
		return (dest);
	d = (char *) dest;
	s = (const char *) src;
	count = (int) n;
	while (count >= 0)
	{
		d[count] = s[count];
		count--;
	}
	return (dest);
}
