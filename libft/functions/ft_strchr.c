/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:25:20 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/22 13:50:42 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[counter])
	{
		if (s[counter] == c)
		{
			return ((char *) s + counter);
		}
		counter++;
	}
	return (NULL);
}
