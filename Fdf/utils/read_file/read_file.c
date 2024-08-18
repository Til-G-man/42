/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:59:38 by tilman            #+#    #+#             */
/*   Updated: 2024/08/18 15:04:28 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

t_file	*read_file(t_file *file)
{
	if (!file->fd)
	{
		ft_printf("Error while reading File\n");
		return (NULL);
	}

	return (file);
}