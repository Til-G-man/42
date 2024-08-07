/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:22:40 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/07 23:54:50 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	wordsize(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**write_array(char **array, char const *s, char c)
{
	int	array_iterator;
	int	word_iterator;

	array_iterator = 0;
	word_iterator = 0;
	while (array_iterator < count_words(s, c))
	{
		while (s[word_iterator] == c)
			word_iterator++;
		array[array_iterator] = (char *)
			malloc(sizeof(char) * (wordsize(&s[word_iterator], c)) + 1);
		if (!array[array_iterator])
		{
			while (array_iterator--)
				free(array[array_iterator]);
			free(array);
			return (NULL);
		}
		ft_strlcpy(array[array_iterator], &s[word_iterator],
			wordsize(&s[word_iterator], c) + 1);
		array_iterator++;
		word_iterator += wordsize(&s[word_iterator], c);
	}
	array[array_iterator] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	return (write_array(array, s, c));
}

//make
//cc ft_split.c libft.a
//int main(void)
//{
//	char	*str = "Hallo";
//	char	**test;

//	test = ft_split(str, ' ');
//	printf("%s\n", test[0]);
//	if (test[1])
//		printf("%s\n", test[1]);
//}