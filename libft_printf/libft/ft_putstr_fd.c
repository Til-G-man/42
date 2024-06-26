/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:22:41 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/13 16:10:39 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return ((int) ft_strlen(s));
}
