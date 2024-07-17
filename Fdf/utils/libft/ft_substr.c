/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:48:30 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/07 15:31:12 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fck25lines(char *str, const char *s, int start, size_t len)
{
	int	counter;

	counter = 0;
	while (len > 0 && s[start] != '\0')
	{
		str[counter] = s[start];
		len--;
		start++;
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if ((signed int)(ft_strlen(s) - start) < (int) len)
		len = ft_strlen(s) - start;
	else if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str = fck25lines (str, s, start, len);
	return (str);
}
