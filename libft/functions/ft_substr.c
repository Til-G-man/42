/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:48:30 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/24 12:36:32 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		counter;

	str = malloc((int) len + 1);
	if (str == NULL || s == NULL || ft_strlen(s) < start)
		return (0);
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
