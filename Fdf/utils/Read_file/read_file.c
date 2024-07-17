/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:20:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/17 17:19:05 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This Funktion gets a fd and returns its values in an 3D array
*/

#include "read_file.h"


void	read_file(char *path)
{
	int	fd;
	char *line;
	char *file;

	printf("Reading file");
	file = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error while open file\n");
		exit(1);
	}
	line = get_next_line(fd);
	while(line)
	{
		file = ft_strjoin_free(file, line);
		line = get_next_line(fd);
	}
	printf("\nFile:\n '%s'", file);
}
