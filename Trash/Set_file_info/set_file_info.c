/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:20:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/18 22:18:15 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_file_info.h"

int	count_char(char *str, char chr)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == chr)
			count++;
		*str++;
	}
	printf("found %i new lines\n", count);
	return (count);
}

//array [lines/hight][collumns][x,y,z,collour]
int	create_array(struct s_Fileinfo *file, char *str)
{
	int	**array[file->array_y][file->array_x][3];
	int	count_x;
	int	count_y;
	int	x;
	int	y;

	count_x, count_y = 0, 0;
	printf("create array\n");
	while (*str)
	{
		while (*str == ' ')
			*str++;
        if (file->array_x == 0 || file->array_y == 0) {
            fprintf(stderr, "Error: array dimensions cannot be zero\n");
            return 1;
        }
		x = file->width_win / file->array_x * count_x;
		y = file->height_win / file->array_y * count_y;
		array[count_y][count_x][0] = x;
		array[count_y][count_x][1] = y;
		count_x++;
		if (*str == '\n')
		{
			count_x = 0;
			count_y++;
		}
		str++;
	}
	return (0);
}

void	set_file_info(struct s_Fileinfo *file)
{
	char *line;
	char *str;

	printf("Reading str\n");
	str = 0;
	line = get_next_line(file->fd);
	while(line)
	{
		str = ft_strjoin_free(str, line);
		line = get_next_line(file->fd);
	}
	if (line)
		free(line);
	printf("\nstr:\n '%s'\n", str);
	file->array_x = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	file->array_y = count_char(str, '\n');
	file->width_win = 600;
	file->height_win = 600;
	//printf("Struct:a_x = %i\na_y = %i\nw_w = %i\nh_w = %i", file->array_x, file->array_y, file->width_win, file->height_win);
	create_array(file, str);
}
