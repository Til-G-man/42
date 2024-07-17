/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:20:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/17 13:12:43 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This Funktion gets a fd and returns its values in an 3D array
*/
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "read_file.h"


void	read_file(char *FILE)
{
	int	fd;
	int x;
	int y;
	char *line;
	int file;

	fd = open("test.fdf", FILE);
	if (fd == -1)
	{
		printf("Error while open file\n");
		exit(1);
	}
	while(line)
	{
		line = get_next_line(fd);
		file = ft_strjoin_free(file, line);
	}
	printf("\nFile:\n '%s'", file);
}
