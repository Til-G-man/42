/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:29:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/19 16:52:13 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <bsd/string.h>

int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isalnum(char c);
int	ft_isascii(char c);
int	ft_isprint(char c);
size_t	ft_strlen(const char *str);
void	*ft_memset(char *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


void	testing_isalpha(void)
{
	printf("Testing isalpha:\n");
	printf("isalpha funktion with input    'C': %d\n", isalpha('C'));
	printf("ft_isalpha funktion with input 'C': %d\n", ft_isalpha('C'));
	printf("isalpha funktion with input    'h': %d\n", isalpha('h'));
	printf("ft_isalpha funktion with input 'h': %d\n", ft_isalpha('h'));
	printf("isalpha funktion with input    '!': %d\n", isalpha('!'));
	printf("ft_isalpha funktion with input '!': %d\n", ft_isalpha('!'));
	printf("\n\n\n");
}

void	testing_isdigit(void)
{
	printf("Testing isdigit:\n");
	printf("isdigit with input      5: %d\n", isdigit(5));
	printf("ft_isdigit with input   5: %d\n", ft_isdigit(5));
	printf("isdigit with input    '5': %d\n", isdigit('5'));
	printf("ft_isdigit with input '5': %d\n", ft_isdigit('5'));
	printf("isdigit with input     21: %d\n", isdigit(21));
	printf("ft_isdigit with input  21: %d\n", ft_isdigit(21));
	printf("isdigit with input    'A': %d\n", isdigit('A'));
	printf("ft_isdigit with input 'A': %d\n", ft_isdigit('A'));
	printf("\n\n\n");
}

void	testing_isalnum(void)
{
	printf("Testing isalnum:\n");
	printf("isalnum with input      3: %d\n", isalnum(3));
	printf("ft_isalnum with input   3: %d\n", ft_isalnum(3));
	printf("isalnum with input    '3': %d\n", isalnum('3'));
	printf("ft_isalnum with input '3': %d\n", ft_isalnum('3'));
	printf("isalnum with input    '?': %d\n", isalnum('?'));
	printf("ft_isalnum with input '?': %d\n", ft_isalnum('?'));
	printf("isalnum with input    'k': %d\n", isalnum('k'));
	printf("ft_isalnum with input 'k': %d\n", ft_isalnum('k'));
	printf("\n\n\n");
}

void	testing_isascii(void)
{
	printf("Testing isascii:\n");
	printf("isascii with input      '5': %d\n", isascii('5'));
	printf("ft_isascii with input   '5': %d\n", ft_isascii('5'));
	printf("isascii with input        5: %d\n", isascii(5));
	printf("ft_isascii with input     5: %d\n", ft_isascii(5));
	printf("isascii with input      'A': %d\n", isascii('A'));
	printf("ft_isascii with input   'A': %d\n", ft_isascii('A'));
	printf("isascii with input     '\\0': %d\n", isascii('\0'));
	printf("ft_isascii with input  '\\0': %d\n", ft_isascii('\0'));
	printf("\n\n\n");
}

void	testing_isprint(void)
{
	printf("Testing isprint:\n");
	printf("isprint with input     'a': %d\n", isprint('a'));
	printf("ft_isprint with input  'a': %d\n", ft_isprint('a'));
	printf("isprint with input     '6': %d\n", isprint('6'));
	printf("ft_isprint with input  '6': %d\n", ft_isprint('6'));
	printf("isprint with input       6: %d\n", isprint(6));
	printf("ft_isprint with input    6: %d\n", ft_isprint(6));
	printf("isprint with input     ' ': %d\n", isprint(' '));
	printf("ft_isprint with input  ' ': %d\n", ft_isprint(' '));
	printf("isprint with input '   \\0': %d\n", isprint('\0'));
	printf("ft_isprint with input '\\0': %d\n", ft_isprint('\0'));
	printf("\n\n\n");
}

void	testing_strlen(void)
{
	printf("Testing strlen:\n");
	printf("strlen with input 'Hello World'    : %ld\n", strlen("Hello World"));
	printf("ft_strlen with input 'Hello World' : %ld \n", strlen("Hello World"));
	printf("strlen with input '\\n'            : %ld \n", strlen("\n"));
	printf("ft_strlen with input '\\n'         : %ld \n", strlen("\n"));
	printf("\n\n\n");
}

void	testing_memset(void)
{
	printf("Testing memset:\n");
	char	buffer1[10];
	char	buffer2[10];
	char	value = '5';
	size_t	num_bytes = sizeof(buffer1);
	char	*original;
	char	*own;
	int		count = 0;
	int		int_bytes = (int) num_bytes;

	original = memset(buffer1, value, num_bytes);
	own = ft_memset(buffer2, value, num_bytes);
	printf("test with input memset(10, %c, %zu)\n", value, num_bytes);
	if (memcmp(buffer1, buffer2, num_bytes) == 0)
		printf("Test 1: the results are identical.\n");
	else
		printf("Test 1: the results are not identical.\n");
	printf("Original:\n");
	while (count < int_bytes)
	{
		printf("%c", original[count]);
		count++;
	}
	printf("\nOwn funktion:\n");
	count = 0;
	while (count < int_bytes)
	{
		printf("%c", own[count]);
		count++;
	}
	printf("\n\n\n");
}

void testing_memset2() {
    char buffer[10];

    // Testfall 1: Füllen mit 'A' über die gesamte Länge
    printf("Test ft_memstet (test written by AI)\n");
	memset(buffer, 0, sizeof(buffer)); // Zuerst den Buffer leeren
    ft_memset(buffer, 'A', sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); i++) {
        if (buffer[i] != 'A') {
            printf("Testcase 1 failed on index %zu\n", i);
            return;
        }
    }
    printf("Testcase 1 succeeded.\n");

    // Testfall 2: Füllen mit Null-Bytes
    memset(buffer, 'A', sizeof(buffer)); // Buffer mit 'A' füllen
    ft_memset(buffer, '\0', 5); // Erste Hälfte mit Null-Bytes füllen
    for (size_t i = 0; i < 5; i++) {
        if (buffer[i] != '\0') {
            printf("Testcase 2 failed on index %zu\n", i);
            return;
        }
    }
    for (size_t i = 5; i < sizeof(buffer); i++) {
        if (buffer[i] != 'A') {
            printf("Testcase 2 failed on index %zu\n", i);
            return;
        }
    }
    printf("Testcase 2 succeeded.");
	printf("\n\n\n");

}

void	testing_bzero(void)
{
	printf("Testing bzero:\n");
    char    buffer1[10];
    char    buffer2[10];
    size_t    num_bytes = sizeof(buffer1);
    int        count = 0;
    int        int_bytes = (int) num_bytes;

	bzero(buffer1, num_bytes);
	ft_bzero(buffer2, num_bytes);
    printf("test with input bzero(10, %zu)\n", num_bytes);
    if (memcmp(buffer1, buffer2, num_bytes) == 0)
        printf("Test 1: the results are identical.\n");
    else
	    printf("Test 1: the results are not identical.\n");
	printf("Original:\n");
	while (count < int_bytes)
	{
        printf("%c", buffer1[count]);
        count++;
    }
	printf("eof\nOwn funktion:\n");
	count = 0;
	while (count < int_bytes)
	{
        printf("%c", buffer2[count]);
        count++;
    }
	printf("eof\n\n\n");
}

void testing_memcpy(void)
{
	printf("Testing memcpy:\n");
    char    dest[10];
    char    src[10];
    size_t    num_bytes = sizeof(dest);
    int        count = 0;
    int        int_bytes = (int) num_bytes;

    memcpy(dest, src, num_bytes);
    ft_memcpy(src, dest, num_bytes);
    printf("test with input memcpy(buffer1, buffer2, %zu)\n", num_bytes);
    if (memcmp(dest, src, num_bytes) == 0)
        printf("Test 1: the results are identical.\n");
    else
        printf("Test 1: the results are not identical.\n");
    printf("Original:\n");
    while (count < int_bytes)
	{
        printf("%c", dest[count]);
        count++;
    }
	printf("\nOwn funktion:\n");
	count = 0;
	while (count < int_bytes)
	{
        printf("%c", src[count]);
        count++;
    }
	printf("\n\n\n");
}

void	testing_memmove(void)
{
	char    org_src[] = "Hello World";
	char    org_dest[10];
	char    own_src[] = "Hello World";
	char    own_dest[10];
	char	*org_try;
	char	*own_try;
	int		size = 5;
	int		count = 0;

	printf("Testing memmove:\n");
	printf("test with input memmove(%s, dest[%lu], %d)\n", org_src, sizeof(org_dest), size);
	printf("test with input ft_memmove(%s, dest[%lu], %d)\n", own_src, sizeof(own_dest), size);
	org_try = memmove(org_src, &org_dest, size);
	own_try = ft_memmove(&own_src, &own_dest, size);
	if (memcmp(org_try, own_try, size) == 0)
	    printf("Test 1: the results are identical.\n");
	else
	    printf("Test 1: the results are not identical.\n");
	printf("Original:\n");
	while (count < size)
	{
        printf("%c", org_dest[count]);
        count++;
    }
	printf("\nOwn funktion:\n");
	count = 0;
	while (count < size)
	{
        printf("%c", own_dest[count]);
        count++;
    }
	printf("\n\n\n");
}
/*
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
*/

int	main(void)
{
	testing_isalpha();
	testing_isdigit();
	testing_isalnum();
	testing_isascii();
	testing_isprint();
	testing_strlen();
	testing_memset();
	testing_memset2();
	testing_bzero();
	testing_memcpy();
	testing_memmove();
	//const char	src[] = "Hello, World!";
	//char	dst1[20];
	//size_t	siz = 20;
	//printf("testtest%zu", strlcpy(dst1, src, siz));
	//testing_ft_strlcpy();
	//testing_ft_strlcat();
}
