#include "libft.h"
#include <stdio.h>

int main() {
	char str[] = "Hello, World!";
	size_t len;

	// Reset str for next test
	char str2[] = "Hello, World!";


	// Test ft_memmove
	// Demonstrating with overlapping regions
	ft_memmove(str2 + 6, str2, ft_strlen(str2));
	printf("After ft_memmove: %s\n", str2);

	printf("test isalpha: %d\n", ft_isalpha(str[0]));

	return 0;
}
