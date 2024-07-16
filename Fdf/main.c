/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:08:44 by tilman            #+#    #+#             */
/*   Updated: 2024/07/16 11:14:44 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int	draw_line(void *mlx_ptr, void *win_ptr, int y)
{
	int	check;
	int	x;
	int	i;

	i = 0;
	check = 1;
	while (check)
	{
		printf("in Loop");
		check = mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xFFFFFF);
		check = mlx_pixel_put(mlx_ptr, win_ptr, x++, y + 1, 0xFFFFFF);
		check = mlx_pixel_put(mlx_ptr, win_ptr, x++, y + 2, 0xFFFFFF);
	}
	printf("line printed");
	return (0);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "testwindow");
	draw_line(mlx, win, 100);
	// mlx_pixel_put(mlx, win, 100, 100, 0xFFFFFF);
	// sleep(1);
	// mlx_pixel_put(mlx, win, 200, 200, 0xFFFFFF);
	// sleep(1);
	// mlx_pixel_put(mlx, win, 300, 300, 0xFFFFFF);
	mlx_loop(mlx);
	// sleep(1);
	// draw_line(mlx, win, 200);
	// sleep(1);
	// draw_line(mlx, win, 300);
    return (0);
}
