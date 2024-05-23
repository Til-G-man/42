/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:20:30 by tilman            #+#    #+#             */
/*   Updated: 2024/05/23 19:00:36 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//gets the fd and read in BUFFERSIZE blocks until a newline is found - Returns a string
char	*readtillnewline(fd)
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

// gets 2 strings and merge them - returns the new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		strlen1;
	int		strlen2;
	int		i;
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
	while (s1 && s1[i])
		str[i++] = s1[i];
	while (s2 && s2[i - strlen1])
		str[i++] = s2[i - strlen1];
	str[strlen1 + strlen2] = '\0';
	return (str);
}

// gets 2 strings and split them on \n - returns the front string includet \n and \0
char	*splitbufferfront(char *buffer, int EOF)
{
	char	temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (ft_str_chr(buffer, '\n') + 2));
	if (temp == NULL)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i]!= '\n')
		temp[i++] = buffer[i];
	if (buffer[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

// gets 2 strings and split them on \n - returns the back string includet \0
char	*splitbufferback(buffer)

char	get_next_line(int fd)
{
	static char	*buffer;
	char		temp;
	int			EOF;
	int			buffersize;

	EOF = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if(!buffer)
	{
		buffer = readtillnewline(fd);
		if (sizeof(buffer) < BUFFER_SIZE)
			EOF = 1;
	}
	else if (0 > ft_strchr(buffer, '\n'))
	{
		buffersize = sizeof(buffer);
		buffer = ft_strjoin(buffer, readtillnewline(fd));
		if (sizeof(buffer) < BUFFER_SIZE + buffersize)
			EOF = 1;
	}
	if (0 <= ft_strchr(buffer, '\n'))
	{
		temp = splitbufferfront(buffer, EOF);
		buffer = splitbufferback(buffer);
	}
	retrun (temp);
}
