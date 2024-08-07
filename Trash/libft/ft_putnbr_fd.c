/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:57:15 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/08 14:00:51 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fd(int nbr, int fd, int count)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
		count++;
	}
	if (nbr >= 10)
	{
		count = ft_putnbr_fd(nbr / 10, fd, count);
		count = ft_putnbr_fd(nbr % 10, fd, count);
	}
	else
	{
		c = nbr + '0';
		write(fd, &c, 1);
		count++;
	}
	return (count);
}
