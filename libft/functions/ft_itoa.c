/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:46:27 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/24 22:33:18 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	array_len(int n)
{
	int    len;

    len = 0;
    while (n!= 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char	*get_array(int n, char **array)
{
	int		array_iterator;
	char	int_to_char;

	array_iterator = 0;
	while(n!= 0)
	{
		int_to_char = n % 10 + '0';
		array[array_iterator] = &int_to_char;
		n = n / 10;
		array_iterator--;
	}
	array[array_iterator] = 0;
	return (*array);
}

char *ft_itoa(int n)
{
	char	**return_array;

	return_array = (char **)malloc(sizeof(char *) * (array_len(n) + 1));
	if (return_array == NULL)
		return (NULL);
	return (get_array(n, return_array));
}
