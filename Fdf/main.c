/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:08:44 by tilman            #+#    #+#             */
/*   Updated: 2024/08/23 16:12:59 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx-linux/mlx.h"
//#include "utils/utils.h"
#include <stdlib.h>
//#include <unistd.h>
#include <stdio.h>
#include "utils/utils.h"

void print_file(t_file *file)
{
    if (file == NULL)
    {
        printf("File is NULL\n");
        return;
    }
    printf("max_x: %d\n", file->max_x);
    printf("max_y: %d\n", file->max_y);
    printf("max_z: %d\n", file->max_z);
    printf("min_z: %d\n", file->min_z);
    printf("fd: %d\n", file->fd);
    printf("list: %p\n", (void *)file->list); // Zeiger auf die Liste ausgeben
    printf("win_x: %d\n", file->win_x);
    printf("win_y: %d\n", file->win_y);
}

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
	printf("show graphic\n");
	show_graphic(file);
	printf("show graphic done\n");
	printf("user control\n");
	user_control(file);
	printf("\nBeende das programm\n");
	printf("final list:\n");
	//print_list(file->list);
	//print_file(file);
	delete_list(file->list);
	printf("Program beendet.\n");
	return (0);
}

