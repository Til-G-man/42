/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:20:30 by tilman            #+#    #+#             */
/*   Updated: 2024/06/03 09:56:41 by tilman           ###   ########.fr       */
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

// gets a string and copies the string to a new location returns a pointer to the new string (the original still exist)
char	*ft_strdup(char *s)
{
	char	*str;
	int		counter;

	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		str[counter] = s[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
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

// gets 2 strings and merge them - returns the new string - the input strings get freed
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		strlen1;
	int		strlen2;
	int		i;
	strlen1 = ft_strlen((char *) s1);
	strlen2 = ft_strlen((char *) s2);
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
	str[strlen1 + strlen2 - 1] = '\0';
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
	if (buffer)
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
	// if (ft_strchr(buffer, '\n') == -1)
	// 	free (buffer);
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

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!buffer)
		buffer = readtillnewline(fd);
	if (!buffer)
		return (NULL);
	else if (0 > ft_strchr(buffer, '\n'))
		buffer = ft_strjoin(buffer, readtillnewline(fd));
	if (0 <= ft_strchr(buffer, '\n'))
	{
		free (temp);
		temp = splitbufferfront(buffer);
		buffer = splitbufferback(buffer);
	}
	else
	{
		free (temp);
		return (buffer);
	}
	return (temp);
}
