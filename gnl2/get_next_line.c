/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:20:30 by tilman            #+#    #+#             */
/*   Updated: 2024/05/24 18:50:55 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

// gets a string and counts the len - rteturn the len
size_t	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// gets a string and a cahr and seachr for the char - returns the index of char or -1 if not found
int	ft_strchr(const char *s, int c)
{
    int		counter;

	if (!s)
	{
		//printf("ft_ft_strchr: s ist NULL\n");
		return (-1);
	}
	//printf("ft_ft_strchr: s ist nicht NULL\n");
    if (c == '\0')
    {
        //printf("ft_ft_strchr: Suche nach '\\0'\n");
		return (ft_strlen((char *)s));
    }
	//printf("ft_ft_strchr: Suche nach Zeichen: '%c' in string '%s'\n", c, s); // Markierung vor Schleife
	counter = 0;
	while (s[counter] && s)
    {
		//printf("Checking sign %c\n", s[counter]); // Hinzugefügt für Debugging
		if (s[counter] == c)
        {
            //printf("ft_ft_strchr: Zeichen gefunden an Position %d\n", counter);
            return (counter);
        }
        counter++;
    }
    //printf("ft_ft_strchr: Zeichen nicht gefunden\n");
    return (-1);
}

// gets 2 strings and merge them - returns the new string
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		strlen1;
	int		strlen2;
	int		i;
	//printf("starting ft_strjoin\n");
	strlen1 = ft_strlen((char *) s1);
	strlen2 = ft_strlen((char *) s2);
	//printf("ft_strjoin: try to malloc\n");
	str = malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[i - strlen1])
	{
		str[i] = s2[i - strlen1];
		i++;
	}
	str[strlen1 + strlen2] = '\0';
	free(s1);
	free(s2);
	return (str);
}


//gets the fd and read in BUFFER_SIZE blocks until a newline is found - Returns a string which contains the '\n' and problably more
char	*readtillnewline(int fd)
{
	char	*temp;
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	// temp = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	temp = NULL;
	// if(!temp)
	// 	return (NULL);
	while (ft_strchr(temp, '\n') == -1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			return (NULL);
		buffer[i] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free (buffer);
	return (temp);
}

// gets 2 strings and split them on \n - returns the front string includet \n and \0
char	*splitbufferfront(char *buffer)
{
	char	*temp;
	int		i;
	int		allocate;

	if (ft_strchr(buffer, '\n') == -1)
		allocate = sizeof(char) * (ft_strlen(buffer) + 2);
	else
		allocate = sizeof(char) * (ft_strchr(buffer, '\n') + 2);
	temp = (char *)malloc(allocate);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i]!= '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// gets a strings and split them on \n - returns the back string includet \0
char	*splitbufferback(char *buffer)
{
	char	*temp;
	int		i;
	int		allocate;

	if (ft_strchr(buffer, '\n') == -1 || !buffer)
		return (NULL);
	allocate = sizeof(char) * (ft_strlen(buffer) - ft_strchr(buffer, '\n') + 1);
	temp = (char *)malloc(allocate);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	buffer += i;
	i = 0;
	while (buffer[i + 1]!= '\0')
	{
		temp[i] = buffer[i + 1];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	// int			eof;
	// int			buffer_size;

	//printf("starting get_next_line\n");
	// if (buffer)
	//  	printf("buffer[0] = '%c'\nbuffer is: \n##########\n\n##########\n", buffer[0]);
	// eof = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("going throu cases\n");
	if(!buffer)
	{
		//printf("buffer is NULL\n");
		buffer = readtillnewline(fd);
		//printf("buffer is : \n##########\n%s\n##########\n", buffer);
		// if (sizeof(buffer) < BUFFER_SIZE)
		// 	eof = 1;
	}
	else if (0 > ft_strchr(buffer, '\n'))
	{
		//printf("buffer is not NULL but no newline found\n");
		// buffer_size = sizeof(buffer);
		buffer = ft_strjoin(buffer, readtillnewline(fd));
		// if (sizeof(buffer) < BUFFER_SIZE + buffer_size)
		// 	eof = 1;
	}
	if (0 <= ft_strchr(buffer, '\n'))
	{
		//printf("newline found in buffer\n");
		temp = splitbufferfront(buffer);
		buffer = splitbufferback(buffer);
	}
	else
	{
		temp = buffer;
		buffer = NULL;
	}
	//printf("temp is: \n##########\n'%s'\n##########\n", temp);
	return (temp);
}
