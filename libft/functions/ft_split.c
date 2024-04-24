/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:22:40 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/24 20:40:58 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int	count_words(char const *s, char c)
{
	int	word_count;
	int	in_word ;

	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			word_count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (word_count);
}

int	wordsize(char const *s, char c)
{
	int	size;

	size = 0;
	while (s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
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
			return (NULL);
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
	array = (char **)malloc(sizeof(char *) * (count_words(s, c)) + 1);
	if (!array)
		return (NULL);
	return (write_array(array, s, c));
}
