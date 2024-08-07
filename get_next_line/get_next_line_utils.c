/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:00:34 by tilman            #+#    #+#             */
/*   Updated: 2024/07/03 14:07:49 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// gets a string and an int as input
// copy the string into a new string and returns it
// it only copy n chars
char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

	if (!str || !len)
		return (NULL);
	count = -1;
	array = (char *)malloc((len + 1) * sizeof(char));
	while (++count < len)
		array[count] = str[count];
	array[count] = '\0';
	return (array);
}

// gets 2 strings as input
// creates a new sting and put both strings inside (fist s1)
// returns the new string and free s1 (s2 is still alloc)
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	len = len + ft_strlen(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	free(s1);
	return (array);
}

// gets a string as input
// returns 1 if the string contais a new line and 0 if not
int	have_n(char	*temp)
{
	int		i;

	if (!temp)
		return (0);
	i = -1;
	while (temp[++i])
		if (temp[i] == 10)
			return (1);
	return (0);
}

// gets a pointer to a pointer to a string as input
//"splits" the string on the first '\n'
// the input pointer gets change so it points on the right side
// it returns the left side of the "split" string
char	*print_line(char **temp)
{
	int		counter;
	char	*return_line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	counter = 0;
	while (str[counter] && str[counter] != 10)
		counter++;
	if (str[counter] == 10)
		counter++;
	return_line = ft_strdup(str, counter);
	*temp = ft_strdup(str + counter, ft_strlen(str + counter));
	if (str)
		free(str);
	str = NULL;
	return (return_line);
}
