/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:08:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/18 14:04:30 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx-linux/mlx.h"
//#include "utils/utils.h"
#include <stdlib.h>
//#include <unistd.h>
#include <stdio.h>
#include "utils/utils.h"

struct  Fileinfo
{
	int		fd;
	int		width;
    int     height;
    char    *filepath;

};

int main(int argc, char *argv[])
{
	// Überprüfen, ob der Dateiname als Argument übergeben wurde
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	fd = fopen(argv[1], "r");
	//read_file("/home/tilman/1Tilman Glücklich/Code/C/42_git/Fdf/maps/test_maps/10-2.fdf");
	printf("Start Program\n");
	read_file(fd);
	printf("\nBeende das programm\n");
	//get_next_line(-1);
	return (0);
}
