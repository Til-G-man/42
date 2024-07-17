/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:07:59 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/26 14:25:12 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *) s;
	counter = 0;
	while (counter < n)
	{
		ptr[counter] = 0;
		counter++;
	}
}
