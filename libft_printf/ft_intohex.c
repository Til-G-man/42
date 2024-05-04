/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:35:32 by tilman            #+#    #+#             */
/*   Updated: 2024/05/04 15:10:43 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_intohex(unsigned int nbr, int capital)
{
	char	*hex_digits;

	if (capital == 0)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_intohex(nbr / 16, capital);
		ft_intohex(nbr % 16, capital);
	}
	else
	{
		write(1, &hex_digits[nbr], 1);
	}
}
