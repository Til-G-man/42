#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;
	char *RED = "\033[31m";
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";

	i = 0;
	fd = open("testtext.txt", O_RDONLY);
	while (i < 3)
	{
		printf("%s\nline %i: %s", GREEN, i, RESET);
		printf("%s%s%s",GREEN, get_next_line(fd), RESET);
		i++;
	}
	close(fd);
	return (0);
}
