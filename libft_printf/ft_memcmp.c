/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:57:00 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/03 17:03:02 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			counter;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (str1[counter] != str2[counter])
			return (str1[counter] - str2[counter]);
		counter++;
	}
	return (0);
}
