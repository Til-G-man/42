/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_graphic.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:55:17 by tilman            #+#    #+#             */
/*   Updated: 2024/08/23 15:59:14 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_GRAPHIC_H
# define SHOW_GRAPHIC_H

#define M_PI 3.14159265358979323846
//https://github.com/42Paris/minilibx-linux/blob/master/man/man1/mlx_new_image.1
# include "../utils.h"
# include <math.h>
# include "../../minilibx-linux/mlx.h"
# include <stdio.h>

int	show_graphic(t_file *file);

#endif