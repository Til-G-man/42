/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/23 17:17:01 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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



char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*return_str;
	char		*buffer;
	int			backslashn;

	return_str = NULL;
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
*/

char	*get_read(char *buffer, int fd)
{
    char	*temp;
    int		newline;

    //printf("get_read: Start\n"); // Markierung am Anfang der Funktion

    if(0 > ft_ft_strchr(buffer, '\n'))
    {
        //printf("get_read: Kein Zeilenumbruch in buffer gefunden\n");
        newline = -1;
        temp = (char *) malloc(BUFFER_SIZE + (sizeof(char) * 2));
        if (!temp)
        {
            //printf("get_read: malloc für temp fehlgeschlagen\n");
            return (NULL);
        }
        read(fd, temp, BUFFER_SIZE);
        newline = ft_ft_strchr(temp, '\n');
        while (0 > newline && temp)
        {
            //printf("get_read: Schleife, newline: %d\n", newline);
            buffer = ft_strjoin(buffer, temp);
            read(fd, temp, BUFFER_SIZE);
            newline = ft_ft_strchr(temp, '\n');
        }
        if (temp)
        {
            //printf("get_read: temp wird zum buffer hinzugefügt\n");
            buffer = ft_strjoin(buffer, temp);
			//printf("get_read: buffer hinzugefügt buffer: %s\n", buffer);
        }
        free(temp);
    }
    else
    {
        //printf("get_read: Zeilenumbruch in buffer gefunden\n");
    }
    //printf("get_read: Ende\n"); // Markierung am Ende der Funktion
    return (buffer);
}

char	*single_line(char * buffer)
{
	char	*temp;

	temp = ft_ft_strlcpy(buffer, ft_ft_strchr(buffer, '\n'));
	return (temp);
}

char	*free_buffer(char *buffer)
{
	char	*temp;
	int		i;

	while (buffer[i] != '\n')
		i++;
	temp = ft_ft_strlcpy(&buffer[i], ft_strlen(&buffer[i]));
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	char *RED = "\033[31m";
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";
	printf("%sStarting get_next_line\n", RED);
	if (buffer)
		printf("%s\n", buffer);
	if (buffer && ft_ft_strchr(buffer, '\n') > 0)
	{
		printf("gnl: in if\n");
		temp = single_line(buffer);
		printf("got single line: %s\n", temp);
		printf("buffer before free: %s\n", buffer);
		buffer = free_buffer(buffer);
		printf("buffer after free: %s\n", buffer);
		printf("freed buffer in if\n%s", RESET);
		return (temp);
	}
	printf("gnl: in else\n");
	buffer = get_read(buffer, fd);
	//printf("got read\n");
	temp = single_line(buffer);
	//printf("got single line\n");
	buffer = free_buffer(buffer);
	printf("freed buffer\n%s", RESET);
	return (temp);
}
