/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:15:35 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/06 15:05:46 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*return_val;

	return_val = NULL;
	counter = 0;
	while (s[counter])
	{
		if (s[counter] == c)
		{
			return_val = (char *)s + counter;
		}
		counter++;
	}
	if (c == '\0')
		return_val = (char *)s + counter;
	return (return_val);
}
