/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:22:55 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/06 17:35:11 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
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

static int	get_end(char const *s1, char const *set)
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
	int		start;
	int		end;

	if (!s1 ||!set)
		return (0);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start == (int) ft_strlen(s1))
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
