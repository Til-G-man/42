/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:36 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/21 17:04:56 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_ft_strlcpy(const char *src, size_t dstsize);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
