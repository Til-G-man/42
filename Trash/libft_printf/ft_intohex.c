/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:35:32 by tilman            #+#    #+#             */
/*   Updated: 2024/05/09 15:18:09 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intohex(unsigned int nbr, int capital, int counter)
{
	char	*hex_digits;

	if (capital == 0)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		counter = ft_intohex(nbr / 16, capital, counter);
		counter = ft_intohex(nbr % 16, capital, counter);
	}
	else
	{
		write(1, &hex_digits[nbr], 1);
		counter++;
	}
	return (counter);
}
