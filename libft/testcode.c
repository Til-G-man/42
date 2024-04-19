#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	str_length(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

void	testing_ft_strlcpy(void)
{
    char	src[] = "Hello, World!";
    char	dst1[20];
    char	dst2[20];
    size_t	result1, result2;

    printf("=== Testing ft_strlcpy ===\n");

    // Test 1: Normal condition
    memset(dst1, 0, sizeof(dst1));
    memset(dst2, 0, sizeof(dst2));
    result1 = ft_strlcpy(dst1, src, sizeof(dst1));
    result2 = strlcpy(dst2, src, sizeof(dst2));
    printf("Test 1: Normal condition\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 1 Passed: ft_strlcpy = %zu, strlcpy = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 1 Failed: ft_strlcpy = %zu, strlcpy = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

    // Test 2: dstsize is smaller than the length of src
    memset(dst1, 'A', sizeof(dst1)); // Initialize with 'A' to check null-termination
    memset(dst2, 'A', sizeof(dst2));
    result1 = ft_strlcpy(dst1, src, 10);
    result2 = strlcpy(dst2, src, 10);
    printf("Test 2: dstsize is smaller than the length of src\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 2 Passed: ft_strlcpy = %zu, strlcpy = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 2 Failed: ft_strlcpy = %zu, strlcpy = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

    // Test 3: dstsize is 0 (should not modify dst and return length of src)
    char small_dst1[1] = "";
    char small_dst2[1] = "";
    result1 = ft_strlcpy(small_dst1, src, 0);
    result2 = strlcpy(small_dst2, src, 0);
    printf("Test 3: dstsize is 0\n");
    if (result1 == result2 && strcmp(small_dst1, small_dst2) == 0)
        printf("\033[0;32mTest 3 Passed: ft_strlcpy = %zu, strlcpy = %zu\n\033[0m", result1, result2);
    else
        printf("\033[0;31mTest 3 Failed: ft_strlcpy = %zu, strlcpy = %zu\n\033[0m", result1, result2);

    printf("\n\n\n");
}

void	testing_ft_strlcat(void)
{
    char	dst1[30] = "Hello, ";
    char	dst2[30] = "Hello, ";
    const char	src[] = "World!";
    size_t	dstsize;
    size_t	result1, result2;

    printf("=== Testing ft_strlcat ===\n");

    // Test 1: Normal condition
    dstsize = sizeof(dst1);
    result1 = ft_strlcat(dst1, src, dstsize);
    result2 = strlcat(dst2, src, dstsize);
    printf("Test 1: Normal condition\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 1 Passed: ft_strlcat = %zu, strlcat = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 1 Failed: ft_strlcat = %zu, strlcat = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

    // Test 2: dstsize is 0
    memset(dst1, 0, sizeof(dst1));
    strcpy(dst1, "Hello, ");
    memset(dst2, 0, sizeof(dst2));
    strcpy(dst2, "Hello, ");
    dstsize = 0;
    result1 = ft_strlcat(dst1, src, dstsize);
    result2 = strlcat(dst2, src, dstsize);
    printf("Test 2: dstsize is 0\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 2 Passed: ft_strlcat = %zu, strlcat = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 2 Failed: ft_strlcat = %zu, strlcat = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

    // Test 3: dstsize is less than the length of dst
    memset(dst1, 0, sizeof(dst1));
    strcpy(dst1, "Hello, ");
    memset(dst2, 0, sizeof(dst2));
    strcpy(dst2, "Hello, ");
    dstsize = 5; // Less than length of dst
    result1 = ft_strlcat(dst1, src, dstsize);
    result2 = strlcat(dst2, src, dstsize);
    printf("Test 3: dstsize is less than the length of dst\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 3 Passed: ft_strlcat = %zu, strlcat = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 3 Failed: ft_strlcat = %zu, strlcat = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

    // Test 4: src is empty
    memset(dst1, 0, sizeof(dst1));
    strcpy(dst1, "Hello, ");
    memset(dst2, 0, sizeof(dst2));
    strcpy(dst2, "Hello, ");
    dstsize = sizeof(dst1);
    result1 = ft_strlcat(dst1, "", dstsize);
    result2 = strlcat(dst2, "", dstsize);
    printf("Test 4: src is empty\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 4 Passed: ft_strlcat = %zu, strlcat = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 4 Failed: ft_strlcat = %zu, strlcat = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

	// Test 5: dstsize is 1
    memset(dst1, 0, sizeof(dst1));
    strcpy(dst1, "Hello, ");
    memset(dst2, 0, sizeof(dst2));
    strcpy(dst2, "Hello, ");
    dstsize = 1;
    result1 = ft_strlcat(dst1, src, dstsize);
    result2 = strlcat(dst2, src, dstsize);
    printf("Test 5: dstsize is 1\n");
    if (result1 == result2 && strcmp(dst1, dst2) == 0)
        printf("\033[0;32mTest 2 Passed: ft_strlcat = %zu, strlcat = %zu, dst = '%s'\n\033[0m", result1, result2, dst1);
    else
        printf("\033[0;31mTest 2 Failed: ft_strlcat = %zu, strlcat = %zu, ft_dst = '%s', dst = '%s'\n\033[0m", result1, result2, dst1, dst2);

    printf("\n\n\n");
}

int	main(void)
{
	testing_ft_strlcpy();
	testing_ft_strlcat();
}
