/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:31:26 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/07 15:27:33 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && len)
	{
		j = 0;
		while (big[i + j] == little[j] && j < len)
		{
			j++;
			if (!little[j])
				return ((char *)(&big[i]));
		}
		i++;
		len--;
	}
	return (NULL);
}
