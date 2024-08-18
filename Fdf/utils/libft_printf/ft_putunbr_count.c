/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:50:37 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/18 12:47:10 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_count(unsigned int nbr, int fd, int count)
{
	char	c;

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
