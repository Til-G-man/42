#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("testtext.txt", O_RDONLY);
	while (i < 3)
	{
		printf("\nline %i: ", i);
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
