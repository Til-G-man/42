/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:20:00 by tilman            #+#    #+#             */
/*   Updated: 2024/05/23 17:20:03 by tilman           ###   ########.fr       */
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
