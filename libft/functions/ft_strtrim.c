/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:22:55 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/24 16:26:25 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	return (start);
}

int	get_end(char const *s1, char const *set)
{
	int	end;
	int	counter;

	end = 0;
	counter = 0;
	while (s1[counter])
	{
		if (!is_in_set(s1[counter], set))
			end = counter + 1;
		counter++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (!s1 ||!set)
		return (0);
	str = malloc(sizeof(char) * (get_end(s1, set) - get_start(s1, set) + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + get_start(s1, set),
		get_end(s1, set) - get_start(s1, set) + 1);
	return (str);
}
