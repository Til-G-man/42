/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:52:47 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/17 22:43:26 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			count;

	d = (char *)dest;
	s = (const char *)src;
	count = 0;
	if (dest < src)
	{
		while (count < (int) n)
		{
			d[count] = s[count];
			count++;
		}
	}
	else if (dest > src)
	{
		while (n > 0)
		{
		    d[n] = s[n];
			n--;
		}
	}
	return (dest);
}
