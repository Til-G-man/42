/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:00:34 by tilman            #+#    #+#             */
/*   Updated: 2024/05/23 18:23:17 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> // Hinzugefügt für printf

size_t	ft_strlen(const char *str)
{
    int	i;

	if (str == NULL)
        return (0);
	i = 0;
    while (str[i])
    {
        i++;
    }
    //printf("ft_strlen: Länge = %d\n", i); // Markierung nach Berechnung der Länge
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    int		strlen1;
    int		strlen2;
	//printf("starting ft_strjoin\n");
    strlen1 = ft_strlen(s1);
    strlen2 = ft_strlen(s2);
	//printf("ft_strjoin: try to malloc\n");
    str = malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (str == NULL)
	{
        //printf("ft_strjoin: malloc fehlgeschlagen\n");
        return (NULL);
    }
	//printf("ft_strjoin: starting movement\n");
    ft_memmove(str, s1, strlen1);
    ft_memmove(str + strlen1, s2, strlen2);
    str[strlen1 + strlen2] = '\0';
    //printf("ft_strjoin: Ergebnis = %s\n", str); // Markierung nach Erstellung des neuen Strings
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
    //printf("ft_memmove: Bewegung abgeschlossen\n"); // Markierung nach Durchführung von memmove
    return (dest);
}

int	ft_ft_strchr(const char *s, int c)
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
        return (ft_strlen(s));
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

char	*ft_ft_strlcpy(const char *src, size_t dstsize)
{
    size_t	i;
    char	*dst;

    if (dstsize == 0)
    {
        //printf("ft_ft_strlcpy: dstsize ist 0, Rückgabe NULL\n");
        return (NULL);
    }
    dst = (char *) malloc(dstsize + 1);
    if (!dst)
    {
        //printf("ft_ft_strlcpy: malloc fehlgeschlagen\n");
        return(NULL);
    }
    i = 0;
    while (src[i] != '\0' && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    //printf("ft_ft_strlcpy: Kopiert = %s\n", dst); // Markierung nach Kopieren
    return (dst);
}
