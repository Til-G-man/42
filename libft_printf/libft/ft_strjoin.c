/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:50:34 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:14 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		strlen1;
	int		strlen2;

	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s1, strlen1);
	ft_memmove(str + strlen1, s2, strlen2);
	str[strlen1 + strlen2] = '\0';
	return (str);
}
