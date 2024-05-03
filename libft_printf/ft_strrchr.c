/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:15:35 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:44 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*return_val;

	return_val = NULL;
	counter = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[counter])
	{
		if (s[counter] == c)
		{
			return_val = (char *)s + counter;
		}
		counter++;
	}
	if (return_val != NULL)
		return (return_val);
	return (NULL);
}
