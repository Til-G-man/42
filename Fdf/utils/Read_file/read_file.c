/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:20:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/16 23:51:38 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This Funktion gets a fd and returns its values in an 3D array
*/
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

int	**array_append(int **array, char *line)
{
	int i;
	int j;
	int **new_array;

	i = 0;
	j = 0;
	while(array[i])
		i++;
	new_array = malloc(sizeof(int *) * (i + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	while(array[i])
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = malloc(sizeof(int) * ft_strlen(line));
	if (!new_array[i])
		return (NULL);
	while(line[j])
	{
		new_array[i][j] = line[j];
		j++;
	}
	new_array[i][j] = '\0';
	new_array[i + 1] = NULL;
	return (new_array);
}

void	read_file(char *FILE)
{
	int	fd;
	int x;
	int y;
	char *line;
	int **array;

	fd = open("test.fdf", FILE);
	if (fd == -1)
	{
		printf("Error while open file\n");
		exit(1);
	}
	while(line)
	{
		line = get_next_line(fd);
		array = array_append(array, line);
	}
}
