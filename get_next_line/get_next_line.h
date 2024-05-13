/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:36 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/13 14:19:56 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// get_next_line.h
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BUFFER_SIZE 4096

char	*get_next_line(int fd);

#endif
