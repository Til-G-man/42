/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:08:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/19 15:29:32 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx-linux/mlx.h"
//#include "utils/utils.h"
#include <stdlib.h>
//#include <unistd.h>
#include <stdio.h>
#include "utils/utils.h"

int	read_3d(int )

int main(int argc, char *argv[])
{
	int	x;
	int	y;
	struct s_Fileinfo *file;
	int	*arr;
	printf("Start Program\n");
	file->check = 0;
	printf("\ncheck: %i shoud be: 0\n", file->check);
	// Überprüfen, ob der Dateiname als Argument übergeben wurde
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	printf("Filename: %s\n", argv[1]);
	file->fd = open(argv[1], O_RDONLY);
	if (file->fd == -1) {
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		return 1;
	}
	printf("fd: %d, %i\n", file->fd, file->fd);
	set_file_info(file);
	x, y = 0;

	printf("fd: %d, %i\n", file->fd, file->fd);
	file->check = 0;
	printf("\ncheck: %i shoud be: 0\n", file->check);
	printf("\nBeende das programm\n");
	return (0);
}
