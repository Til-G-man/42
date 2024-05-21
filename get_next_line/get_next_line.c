/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/21 11:56:29 by tilman           ###   ########.fr       */
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
char	*get_next_line(int fd)
{
	static char	next_line;
	char		*return_str;
	int			counter;
	char		*buffer;
	int			eol;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *) malloc(sizeol(char *) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	eol = 0;
	while (!eol)
	{
		buffer = read(fd, buffer, BUFFER_SIZE);
		if (ft_strrchr(buffer, '\n'))

	}




}
