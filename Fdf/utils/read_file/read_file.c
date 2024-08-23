/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:59:38 by tilman            #+#    #+#             */
/*   Updated: 2024/08/23 14:41:50 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

t_file	get_boundary(t_file *file)
{
	t_list	*node;

	node = file->list;
	while (node)
	{
		node = node->before;
		if (!node->before)
			break;
	}
	while(node)
	{
		if (file->max_x < node->x)
			file->max_x = node->x;
		if (file->max_y < node->y)
			file->max_y = node->y;
		if (file->max_z < node->z)
			file->max_z = node->z;
		if (file->min_z > node->z)
			file->min_z = node->z;
		if (!node->next)
			break;
		node = node->next;
	}
	return (*file);
}

void print_int_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s%d%s ", ORANGE, array[i], RESET);
    }
    printf("\n");
}

int	hex_to_int(char c1, char c2)
{
	char	*hex_lower;
	int		int1;
	int		int2;

	hex_lower = "0123456789abcdef";

	int1 = ft_strlen(hex_lower) - ft_strlen(ft_strchr(hex_lower, ft_tolower(c1)));
	int2 = ft_strlen(hex_lower) - ft_strlen(ft_strchr(hex_lower, ft_tolower(c2)));

	//printf("%schar: %c%c%s\n",GREEN, c1, c2, RESET);
	//printf("%sreturn val: %i\nint1: %i, int2: %i%s", GREEN, int1 * 16 + int2, int1, int2, RESET);
	return(int1 * 16 + int2);
}

int	*get_array(int x, int y, char *z)
{
	int	*array;
	int	count;

	array = (int *)malloc(sizeof(int) * 6);
	if (!array)
		return (NULL);
	array[0] = x;
	array[1] = y;
	array[2] = ft_atoi(z);
	if (ft_strchr(z, 'x') || ft_strchr(z, 'X'))
	{
		count = 0;
		while(z[count] != 'x' && z[count] != 'X')
		{
			count++;
		}
		array[3] = hex_to_int(z[count + 1], z[count + 2]);
		array[4] = hex_to_int(z[count + 3], z[count + 4]);
		array[5] = hex_to_int(z[count + 5], z[count + 6]);
		print_int_array(array, 6);
	}
	else
	{
		array[3] = 0;
		array[4] = 0;
		array[5] = 0;
	}
	return (array);
}

t_list	*insert_list(int array[6], t_file *file)
{
	t_list	*new_node;

	//printf("%sStart inserting%s\n", RED, RESET);
	//printf("x: %i, y:%i, z: %i, colour: %s\n", x, y, array[2], ft_strchr(z, 'x'));
	if (!file->list)
	{
		new_node = init_list(array);
	}
	else
	{
		new_node = append(file->list, array);
	}
	file->list = new_node;
	//printf("inserting done\n");
	return (new_node);
}

t_file	*read_file(t_file *file)
{
	char	*line;
	char	**line_split;
	int		x;
	int		y;
	int		*array;

	//printf("Start Reading File\n");
	if (!file->fd)
	{
		ft_printf("%sError while reading File%s\n", RED, RESET);
		return (NULL);
	}
	line = get_next_line(file->fd);
	y = 1;
	while (line)
	{
		//printf("%sReading new line: '%s'%s\n", GREEN, line, RESET);
		line_split = ft_split(line, ' ');
		x = 1;
		while(line_split[x - 1])
		{
			array = get_array(x, y, line_split[x - 1]);
			insert_list(array, file);
			x++;
		}
		y++;
		line = get_next_line(file->fd);
		//printf("node inserted\n");
	}
	get_boundary(file);
	//printf("done reading file\n");
	return (file);
}