/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:10:45 by tilman            #+#    #+#             */
/*   Updated: 2024/08/23 17:11:42 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"
#include "show_graphic.h"

int rgb_to_int(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

void draw_point(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);

}
void isometric_projection(t_list *list) {
    double theta = M_PI / 6; // 30 degrees
	printf("iso_check1\n");
    list->iso_x = (list->x - list->y) * cos(theta);
	printf("iso_check2\n");
    list->iso_y = (list->x + list->y) * sin(theta) - list->z;
	printf("iso_check3\n");
}

int	show_graphic(t_file *file)
{
	t_list	*list;
	int		colour;

	printf("Start graphic\n");
	file->mlx_ptr = mlx_init();
	if (file->mlx_ptr == NULL)
    {
        printf("Error while mlx_init\n");
		return (1);
    }
	file->win_ptr = mlx_new_window(file->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
    if (file->win_ptr == NULL)
    {
        printf("Error while creating new window\n");
		return (1);
    }
	printf("got mlx- and win-ptr\n");
	list = list_start(file->list);
	while (list)
	{
		printf("start_loop node:\n");
		print_list(list);
		print_node(list);
		isometric_projection(list);
		printf("iso done\n");
		list->iso_x = (list->iso_x + WINDOW_WIDTH / 2);
        list->iso_y = (list->iso_y + WINDOW_HEIGHT / 2);
		colour = rgb_to_int(list->colour_r, list->colour_g, list->colour_b);
		if (colour == 0)
			colour = 0xFF0000;
		draw_point(file->mlx_ptr, file->win_ptr, list->iso_x, list->iso_y, colour);
		printf("show_graphic(): point: x: %i, y: %i\n", list->iso_x, list->iso_y);
		printf("current list: '%p', list->next: %p\n", &list, list->next);
		list = list->next;
		printf("x: %i\n", list->x);
		printf("loop end\n");
	}
	printf("graphic done - sleep 10\n");
	sleep(10);
	return (NULL);
}
