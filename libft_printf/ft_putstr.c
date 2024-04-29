/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:12:20 by tilman            #+#    #+#             */
/*   Updated: 2024/04/29 19:20:04 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}
void	ft_putstr(char *str)
{
	write (1, str, ft_strlen(str));
}

