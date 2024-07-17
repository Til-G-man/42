/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:06:53 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/06 12:46:02 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0 || (!dest && !src))
		return (dest);
	d = (char *) dest;
	s = (const char *) src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
