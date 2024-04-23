/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:23:21 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/23 15:36:40 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*str;
	int		counter;

	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		str[counter] = s[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
