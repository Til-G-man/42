/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:20:04 by tilman            #+#    #+#             */
/*   Updated: 2024/08/08 00:36:21 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"
#include <unistd.h>

//typedef struct file
//{
//	int			max_x;
//	int			max_y;
//	int			max_z;
//	int			min_z;
//	int			max_colour;
//	int			min_colour;
//	int			fd;
//	t_list		*list;
//}	t_file;

int	*create_array(int count_x, int count_y, char *line_split)
{
	int *array;
	char **line_line_split;
	int		number;

	line_line_split = ft_split(line_split, ',');
	array = (int *)malloc(4 * sizeof(int));
	if (array == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	number = ft_atoi(line_line_split[0]);
	printf("Number: %i\n", number);
	array[0] = count_x;
	array[1] = count_y;
	array[2] = number;
	if (line_line_split[1])
	{
		number = line_line_split[1] - '0';
		printf("number_hex: %i, %X	should be: %s", number, number, line_line_split[1]);
		array[3] = number;
	}
	return (array);
}

t_list	*append_list(t_file *file)
{
	int	count_x;
	int	count_y;
	char	**line_split;
	char	*line;

	line = get_next_line(file->fd);
	printf("first line: '%s'\n", line);
	count_y = 0;
	while (line)
	{
		line_split = ft_split(line, ' ');
		count_x = 0;
		while (line_split[count_x])
		{
			printf("%s ", line_split[count_x]);
			append(file->list, create_array(count_x, count_y, line_split[count_x]));
			count_x++;
		}
		free(line);
		line = get_next_line(file->fd);
		printf("\n");
		count_y++;
	}
}
//	int *array = (int *)malloc(4 * sizeof(int));

//	if (array == NULL) {
//		fprintf(stderr, "Memory allocation failed\n");
//		exit(EXIT_FAILURE);
//	}

//	array[0] = x;
//	array[1] = y;
//	array[2] = z;
//	array[3] = colour;

//	return (array);
//}

int	main(void)
{
	int		fd;
	t_file	*file;
	t_list	*list;

	fd = open("/home/tilman/1Tilman Glücklich/Code/C/42_git/Fdf/maps/test_maps/pyramide.fdf", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	printf("file_open\n");
	file->fd = fd;
	file->list = list;
	append_list(file);
	printf("End of read_file\n\n");
}