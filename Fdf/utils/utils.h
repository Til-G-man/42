/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:29:46 by tgluckli          #+#    #+#             */
/*   Updated: 2024/07/18 21:34:55 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H


# include "Get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include "Set_file_info/set_file_info.h"

struct	s_Fileinfo
{
	int		fd;
	int		width_win;
	int		height_win;
	int		**array_points;
	int		*array_color;
	int		array_x;
	int		array_y;
	int		check;

};

#endif
