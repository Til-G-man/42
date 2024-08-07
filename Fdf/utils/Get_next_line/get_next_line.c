/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/07 22:52:32 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char		*temp;
	char			*buffer;
	int				bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp), temp = NULL, NULL);
	if (have_n(temp))
		return (print_line(&temp));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		temp = ft_strjoin_free(temp, buffer);
		if (have_n(temp))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&temp));
}
