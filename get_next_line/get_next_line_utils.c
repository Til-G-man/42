/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:00:34 by tilman            #+#    #+#             */
/*   Updated: 2024/05/21 11:52:51 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		strlen1;
	int		strlen2;

	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s1, strlen1);
	ft_memmove(str + strlen1, s2, strlen2);
	str[strlen1 + strlen2] = '\0';
	return (str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			count;

	d = (char *)dest;
	s = (const char *)src;
	count = 0;
	if (dest < src)
	{
		while (count < (int) n)
		{
			d[count] = s[count];
			count++;
		}
	}
	else if (dest > src)
	{
		count = n - 1;
		while (count >= 0)
		{
			d[count] = s[count];
			count--;
		}
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	char	ch;

	ch = (char)c;
	counter = 0;
	if (ch == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[counter])
	{
		if (s[counter] == ch)
		{
			return ((char *) s + counter);
		}
		counter++;
	}
	return (NULL);
}
