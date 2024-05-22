/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/22 12:36:04 by tgluckli         ###   ########.fr       */
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

	backslashn = 0;
	printf("Starting get_next_line\n");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *) malloc(BUFFER_SIZE);
	//printf("malloced buffer\n");
	if (!buffer)
		return (NULL);
	printf("malloced buffer check\n");
	//if (read(fd, buffer, BUFFER_SIZE) < 0) {
	//	printf("in if check inside");
	//	free(buffer);
	//	return (NULL);
	//}
	//if (next_line && ft_ft_strchr(next_line, '\n') < 0)
	//	return_str = next_line;
	//else if (next_line && ft_ft_strchr(next_line, '\n') >= 0)
	//	return (ft_ft_strlcpy(next_line, ft_ft_strchr(next_line, '\n')));
	//backslashn = ft_ft_strchr(buffer, '\n');
	//if (backslashn == -1)
	printf("vor backslashn=0\n");
	printf("handled next line\n");
	while (!backslashn)
	{
		printf("in loop\n");
		if (read(fd, buffer, BUFFER_SIZE) < 0) {
			free(buffer);
			return (NULL);
		}
		printf("in loop first if check passed\n");
		backslashn = ft_ft_strchr(buffer, '\n');
		if (backslashn >= 0)
		{
			printf("found backslash n in buffer\n");
			return_str = ft_strjoin(return_str, ft_ft_strlcpy(buffer, backslashn));
			printf("got returnstr: %s", return_str);
			next_line = ft_ft_strlcpy(&buffer[backslashn + 1], ft_strlen(buffer) - backslashn - 1);
			printf("got next line: %s", next_line);
			free(buffer);
			return (return_str);
		}
		return_str = ft_strjoin(return_str, buffer);
	}
	free (buffer);
	return (NULL);
}
