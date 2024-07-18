/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:20:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/18 13:47:12 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This Funktion gets a fd and returns its values in an 3D array
*/

#include "read_file.h"


void	read_file(int fd)
{
	int	fd;
	char *line;
	char *file;

	printf("Reading file\n");
	file = 0;
	line = get_next_line(fd);
	while(line)
	{
		file = ft_strjoin_free(file, line);
		line = get_next_line(fd);
	}
	printf("\nFile:\n '%s'", file);

}
