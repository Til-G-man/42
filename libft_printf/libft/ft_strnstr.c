/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:31:26 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:39 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(char *str, char *to_find, size_t len)
{
	int	i;

	i = 0;
	while (str[i] || to_find[i])
	{
		if ((int) len <= i)
			return (0);
		if (!to_find[i])
			return (1);
		else if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	int	i;

	if (!to_find[0])
		return (&str[0]);
	i = 0;
	while (str[i] && len > 0)
	{
		if ((str[i] == to_find[0]) && (is_word(&str[i], to_find, len) == 1))
			return (&str[i]);
		i++;
		len--;
	}
	return (NULL);
}
