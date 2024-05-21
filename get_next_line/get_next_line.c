/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/21 18:14:22 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*next_line;
	char		*line;
	ssize_t		bytes_read;

	if (!next_line)
		next_line = buffer;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if ((line = strchr(buffer, '\n')))
		{
			*line = '\0';
			next_line = strdup(line + 1);
			return (strdup(buffer));
		}
	}
	if (bytes_read == 0 && *next_line)
	{
		line = strdup(next_line);
		*next_line = '\0';
		return (line);
	}
	return (NULL);
}
*/
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*return_str;
	char		*buffer;
	int			backslashn;
	ssize_t		bytes_read;
	printf("Starting get_next_line\n");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	backslashn = 0;
	if (next_line && !ft_ft_strchr(next_line, '\n'))
		return_str = next_line;
	else if (nextline)
	while (!backslashn)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		backslashn = ft_ft_strchr(buffer, '\n');
		if (backslashn)
		{
			return_str = ft_strjoin(return_str, ft_ft_strlcpy(buffer, backslashn));
			next_line = ft_ft_strlcpy(&buffer[backslashn + 1], ft_strlen(buffer) - backslashn - 1);
			return (return_str);
		}
		return_str = ft_strjoin(return_str, buffer);
	}
	free(buffer);
	return (NULL);
}
