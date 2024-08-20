/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:59:38 by tilman            #+#    #+#             */
/*   Updated: 2024/08/20 19:22:10 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	*get_array(int x, int y, int z)
{
	int	array[6];

	array[0] = x;
	array[1] = y;
	array[2] = ft_atoi(z);
	if (ft_strchr(z, 'x') || ft_strchr(z, 'X'))
	{

	}


}

t_list	*insert_list(int array[6], t_file *file)
{
	char	*colour;
	t_list	*new_node;

	printf("%sStart inserting%s\n", RED, RESET);
	//printf("x: %i, y:%i, z: %i, colour: %s\n", x, y, array[2], ft_strchr(z, 'x'));
	if (!file->list)
	{
		printf("inti node\n");
		new_node = init_list(array);
		printf("inti node done\n");
	}
	else
	{
		printf("appent node\n");
		new_node = append(file->list, array);
		printf("appending done\n");
	}
	file->list = new_node;
	printf("inserting done\n");
	return (new_node);
}

t_file	*read_file(t_file *file)
{
	char	*line;
	char	**line_split;
	int		x;
	int		y;

	if (!file->fd)
	{
		ft_printf("%sError while reading File%s\n", RED, RESET);
		return (NULL);
	}
	printf("Start Reading File\n");
	line = get_next_line(file->fd);
	y = 1;
	while (line)
	{
		printf("%sReading new line: '%s'%s\n", GREEN, line, RESET);
		line_split = ft_split(line, ' ');
		x = 1;
		while(line_split[x - 1])
		{
			insert_list(get_array(x, y, line_split[x - 1]), file);
			x++;
		}
		y++;
		line = get_next_line(file->fd);
		printf("node inserted\n");
	}
	return (file);
}