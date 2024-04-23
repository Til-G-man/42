/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:48:30 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/23 16:07:44 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		counter;

	str = malloc(len);
	if (str == NULL)
		return (NULL);
	counter = 0;
	while (len > 0)
	{
		str[counter] = s[start];
		len--;
		start++;
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
