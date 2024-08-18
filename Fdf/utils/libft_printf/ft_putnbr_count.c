/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:57:15 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/18 12:34:46 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int nbr, int fd, int count)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (count + 11);
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count = ft_putnbr_count(nbr / 10, fd, count);
		count = ft_putnbr_count(nbr % 10, fd, count);
	}
	else
	{
		c = nbr + '0';
		write(fd, &c, 1);
		count++;
	}
	return (count);
}
