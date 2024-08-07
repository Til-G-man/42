/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:36 by tgluckli          #+#    #+#             */
/*   Updated: 2024/07/17 17:47:05 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/libft.h"

char	*ft_strdup_gnl(char *str, int len);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_loop(char *str1, char *str2);
int		have_n(char	*temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);

#endif
