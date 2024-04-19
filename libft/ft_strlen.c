/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:34:01 by tilman            #+#    #+#             */
/*   Updated: 2024/04/18 15:42:01 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	str_length(const char *str) {
	size_t length;

	length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}
