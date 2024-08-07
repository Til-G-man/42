/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:26:36 by tilman            #+#    #+#             */
/*   Updated: 2024/08/07 23:33:19 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "../Get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include "../ft_lists/ft_lists.h"

typedef struct file
{
	int			max_x;
	int			max_y;
	int			max_z;
	int			min_z;
	int			max_colour;
	int			min_colour;
	int			fd;
	t_list		*list;
}	t_file;

#endif