/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:07:59 by tilman            #+#    #+#             */
/*   Updated: 2024/04/29 18:47:42 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_nbr(int nbr)
{
	char	num_char;

	num_char = nbr + '0';
	write (1, &num_char, 1);
}

void ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 0)
	{
		ft_putnbr(nbr / 10);
		write_nbr(nbr % 10);
	}
}

int	main(void)
{
	ft_putnbr(2147483647);
}
