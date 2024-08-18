/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:29:46 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/18 11:53:15 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct list
{
	struct list	*before;
	int			x;
	int			y;
	int			z;
	int			colour;
	struct list	*next;
}	t_list;

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
	int			win_x;
	int			win_y;
}	t_file;

# include "Libft/libft.h"
# include "libft_printf/ft_printf.h"
# include "Get_next_line/get_next_line.h"
# include "ft_lists/ft_lists.h"
# include "read_file/read_file.h"

#endif
