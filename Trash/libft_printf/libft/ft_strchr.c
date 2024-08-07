/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:25:20 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/07 11:25:42 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	char	ch;

	ch = (char)c;
	counter = 0;
	if (ch == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[counter])
	{
		if (s[counter] == ch)
		{
			return ((char *) s + counter);
		}
		counter++;
	}
	return (NULL);
}
