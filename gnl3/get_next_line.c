/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:29 by tilman            #+#    #+#             */
/*   Updated: 2024/06/18 15:18:44 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// gets a string and counts the len - return the len
size_t	ft_strlen(char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
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
	int	counter;

	if (!s)
		return (-1);
	if (c == '\0')
		return (ft_strlen((char *)s));
	counter = 0;
	while (s[counter])
	{
		if (s[counter] == c)
			return (counter);
		counter++;
	}
	return (-1);
}

int	split_dup(char *str, char **front, char **back)
{
	int	i;

	i = 0;
	while(*str && *str != '\n' && *front)
		*front[i++] = *str++;
	front[i] = '\0';
	if (*str == '\n')
		*str++;
	i = 0;
	while(*str)
		*back[i++] = *str++;
	*back[i] = '\0';
	return(i);
}

char	*ft_ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		strlen1;
	int		strlen2;

	strlen1 = ft_strlen((char *) s1);
	strlen2 = ft_strlen((char *) s2);
	str = malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (str == NULL)
		return (NULL);
	while (*str && *s1)
		*str++ = *s1++;
	while (*str && *s2)
		*str++ = *s2++;
	str = '\0';
	free(s1);
	return (str);
}


char	*read_line(int fd, char *str, char **buf)
{
	int		i;
	char	*temp[BUFFER_SIZE + 1];
	char	*return_val;

	if (ft_strchr(str, '\n'))
		return (0);
	return_val = ft_ft_strjoin(str, NULL);
	while (ft_strchr(return_val, '\n') < 0);
	{
		i = read(fd, temp, BUFFER_SIZE);
		printf("\n i = BUF_SIZE: %i = %i\n", i, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		return_val = ft_ft_strjoin(return_val, *temp);
	}
	if (i < BUFFER_SIZE && ft_strchr(return_val, '\n') < 0)
		free(buf);
	return(return_val);
}

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE];
	char		*temp;
	int			i;
	char		*test_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(*buffer, '\n') >= 0)
	{
		temp = malloc(sizeof(char *) * ft_strchr(*buffer, '\n') + 1);
		split_dup(buffer[0], &temp, &buffer[0]);
		return (temp);
	}
	else if (buffer)
	{
		temp = malloc(sizeof(char *) * ft_strlen(*buffer) + 1);
		split_dup(buffer[0], &temp, &buffer[0]);

	}
	temp = read_line(fd, temp, &buffer[0]);
	test_str = ft_ft_strjoin(buffer[0], temp);
	free(temp);
	split_dup(test_str, &temp, &buffer[0]);
	free(test_str);
	return (temp);
}
