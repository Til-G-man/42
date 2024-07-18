/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_info.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:20:48 by tilman            #+#    #+#             */
/*   Updated: 2024/07/18 21:23:39 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

#include "../Get_next_line/get_next_line.h"
#include "../Libft/libft.h"
#include "../utils.h"

void	set_file_info(struct s_Fileinfo *file);
int	get_num(char *str);

#endif
