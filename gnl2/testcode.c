#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";
	char *str;

	fd = open("1char.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("line: %s%s%s",GREEN, str, RESET);
		if (str)
			free (str);
		str = get_next_line(fd);
	}
	close(fd);
	get_next_line(fd);
	return (0);
}
