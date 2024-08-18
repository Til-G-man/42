/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:08:44 by tilman            #+#    #+#             */
/*   Updated: 2024/08/18 12:12:52 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx-linux/mlx.h"
//#include "utils/utils.h"
#include <stdlib.h>
//#include <unistd.h>
#include <stdio.h>
#include "utils/utils.h"


int main(int argc, char *argv[])
{
	t_file	*file;

	printf("Start Program\n");
	// Überprüfen, ob der Dateiname als Argument übergeben wurde
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	printf("Filename: %s\n", argv[1]);
	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (1);
	file->fd = open(argv[1], O_RDONLY);
	if (file->fd == -1) {
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		return 1;
	}
	printf("Start reading file: '%i'\n", file->fd);
	read_file(file);
	printf("count: %i\n", count_list(file->list));
	printf("\nBeende das programm\n");
	return (0);
}
