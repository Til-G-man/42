#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";
	char *str;

	i = 0;
	fd = open("testtext.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		//printf("%sin loop\n%s", GREEN, RESET);
		//printf("%sline %i: %s", GREEN, i, RESET);
		printf("%s%s%s",GREEN, str, RESET);
		// printf("calling get_next_line");
		if (str)
			free (str);
		str = get_next_line(fd);
		//printf("Done\n");
	}
	printf("outside of loop");
	close(fd);
	// get_next_line(fd);
	//free (str);
	printf("test");
	return (0);
}
