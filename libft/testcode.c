/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:53:04 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/23 16:21:24 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// to run test execute:
// gcc testcode.c -L. -lft -lbsd -o testprogram
// ./testprogram

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <bsd/string.h>
#include "libft.h"


void testing_ft_isalpha(void) {
	char test_chars[] = {'a', 'Z', '5', '%', '\n', '0', '9', 'A', 'z', 127, '@', '`', '[', '{'};
	int original, custom;
	printf("=== Testing ft_isalpha ===\n");
	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		original = isalpha(test_chars[i]);
		custom = ft_isalpha(test_chars[i]);
		if ((original && custom) || (!original && !custom)) {
			printf("\033[0;32mTest successful for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		} else {
			printf("\033[0;31mTest failed for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_isdigit(void) {
	char test_chars[] = {'0', '5', '9', 'a', 'Z', '%', '\n', ' ', '-', '1', '8'};
	int original, custom;
	printf("=== Testing ft_isdigit ===\n");
	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		original = isdigit(test_chars[i]);
		custom = ft_isdigit(test_chars[i]);
		if ((original && custom) || (!original && !custom)) {
			printf("\033[0;32mTest successful for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		} else {
			printf("\033[0;31mTest failed for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_isalnum(void) {
	char test_chars[] = {'a', 'Z', '5', '%', '\n', '0', '9', 'A', 'z', 127};
	int original, custom;
	printf("=== Testing ft_isalnum ===\n");
	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		original = isalnum(test_chars[i]);
		custom = ft_isalnum(test_chars[i]);
		if ((original && custom) || (!original && !custom)) {
			printf("\033[0;32mTest successful for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		} else {
			printf("\033[0;31mTest failed for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_isascii(void) {
	char test_chars[] = {0, 127, 128, -1, 'a', 'Z', '0', 9, '\n', 255};
	int original, custom;
	printf("=== Testing ft_isascii ===\n");
	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		original = isascii(test_chars[i]);
		custom = ft_isascii(test_chars[i]);
		if ((original && custom) || (!original && !custom)) {
			printf("\033[0;32mTest successful for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		} else {
			printf("\033[0;31mTest failed for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_isprint(void) {
	char test_chars[] = {31, 32, 126, 127, 'a', 'Z', '0', 9, '\n', 255};
	int original, custom;
	printf("=== Testing ft_isprint ===\n");
	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		original = isprint(test_chars[i]);
		custom = ft_isprint(test_chars[i]);
		if ((original && custom) || (!original && !custom)) {
			printf("\033[0;32mTest successful for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		} else {
			printf("\033[0;31mTest failed for: '%c' (Original: %d, Custom: %d)\033[0m\n", test_chars[i], original, custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_strlen(void) {
	const char *test_strings[] = {"", "Hello, World!", "1234567890", "A single character", "\n\t"};
	size_t original, custom;
	printf("=== Testing ft_strlen ===\n");
	for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++) {
		original = strlen(test_strings[i]);
		custom = ft_strlen(test_strings[i]);
		if (original == custom) {
			printf("\033[0;32mTest successful for: \"%s\" (Original: %zu, Custom: %zu)\033[0m\n", test_strings[i], original, custom);
		} else {
			printf("\033[0;31mTest failed for: \"%s\" (Original: %zu, Custom: %zu)\033[0m\n", test_strings[i], original, custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_memset(void) {
	char original[50];
	char custom[50];
	int test_values[] = {0, 'a', 255};
	size_t sizes[] = {5, 10, sizeof(original)};

	printf("=== Testing ft_memset ===\n");
	for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
		for (int j = 0; j < sizeof(sizes) / sizeof(sizes[0]); j++) {
			memset(original, test_values[i], sizes[j]);
			ft_memset(custom, test_values[i], sizes[j]);
			if (memcmp(original, custom, sizes[j]) == 0) {
				printf("\033[0;32mTest successful for value: '%c' and size: %zu\033[0m\n", test_values[i], sizes[j]);
			} else {
				printf("\033[0;31mTest failed for value: '%c' and size: %zu\033[0m\n", test_values[i], sizes[j]);
			}
		}
	}
	printf("\n\n\n");
}

void testing_ft_bzero(void) {
	char buffer1[100];
	char buffer2[100];
	size_t test_sizes[] = {0, 1, 5, 10, 50, 99};

	printf("=== Testing ft_bzero ===\n");
	for (int i = 0; i < sizeof(test_sizes) / sizeof(test_sizes[0]); i++) {
		// Set both buffers with '1' to ensure we can see the zeroing effect
		memset(buffer1, '1', sizeof(buffer1));
		memset(buffer2, '1', sizeof(buffer2));

		// Use ft_bzero on buffer1 and manual zeroing on buffer2 for comparison
		ft_bzero(buffer1, test_sizes[i]);
		for (size_t j = 0; j < test_sizes[i]; j++) {
			buffer2[j] = 0;
		}

		// Compare the results
		if (memcmp(buffer1, buffer2, sizeof(buffer1)) == 0) {
			printf("\033[0;32mTest successful for size: %zu\033[0m\n", test_sizes[i]);
		} else {
			printf("\033[0;31mTest failed for size: %zu\033[0m\n", test_sizes[i]);
		}
	}
	printf("\n\n\n");
}

void testing_ft_memcpy(void)
{
    char src[100] = "Dies ist ein Teststring.";
    char dest[100];
    char original_dest[100];
    size_t n;

    printf("=== Testing ft_memcpy ===\n");

    // Test 1: Normal copy
    n = strlen(src) + 1; // Include null terminator
    memset(dest, 'A', sizeof(dest)); // Fill dest with 'A' to see the copy
    memset(original_dest, 'A', sizeof(original_dest));
    memcpy(original_dest, src, n);
    ft_memcpy(dest, src, n);
    if (memcmp(dest, original_dest, n) == 0)
        printf("\033[0;32mTest 1 passed: Normal copy successful.\033[0m\n");
    else
        printf("\033[0;31mTest 1 failed: Normal copy unsuccessful.\033[0m\n");

    // Test 2: Copy zero bytes
    memset(dest, 'A', sizeof(dest)); // Reset dest
    memset(original_dest, 'A', sizeof(original_dest)); // Reset original_dest
    memcpy(original_dest, src, 0);
    ft_memcpy(dest, src, 0);
    if (memcmp(dest, original_dest, 1) == 0) // Check if the first byte is unchanged
        printf("\033[0;32mTest 2 passed: Zero byte copy successful.\033[0m\n");
    else
        printf("\033[0;31mTest 2 failed: Zero byte copy unsuccessful.\033[0m\n");

    // Test 3: Copy with n greater than string length (should not go past the null terminator)
    n = strlen(src) + 10; // Intentionally larger to test boundary
    memset(dest, 'A', sizeof(dest)); // Reset dest
    memset(original_dest, 'A', sizeof(original_dest)); // Reset original_dest
    memcpy(original_dest, src, n);
    ft_memcpy(dest, src, n);
    if (memcmp(dest, original_dest, n) == 0)
        printf("\033[0;32mTest 3 passed: Over-length copy successful.\033[0m\n");
    else
        printf("\033[0;31mTest 3 failed: Over-length copy unsuccessful.\033[0m\n");

    // Weitere Tests können hier hinzugefügt werden, um spezifische Fälle zu überprüfen.

    printf("\n\n\n"); // 3 Leerzeilen am Ende
}

void testing_ft_memmove(void) {
	char str1[100] = "Hello, world! This is a test string.";
	char str2[100] = "Hello, world! This is a test string.";
	size_t test_sizes[] = {5, 10, 20, 30, 40};

	printf("=== Testing ft_memmove ===\n");
	for (int i = 0; i < sizeof(test_sizes) / sizeof(test_sizes[0]); i++) {
		// Test non-overlapping regions
		char *result_original = memmove(str1 + 50, str1, test_sizes[i]);
		char *result_custom = ft_memmove(str2 + 50, str2, test_sizes[i]);
		if (memcmp(result_original, result_custom, test_sizes[i]) == 0) {
			printf("\033[0;32mNon-overlapping test successful for size: %zu\033[0m\n", test_sizes[i]);
		} else {
			printf("\033[0;31mNon-overlapping test failed for size: %zu original: %s | own: %s\033[0m\n", test_sizes[i], result_original, result_custom);
		}

		// Reset strings
		strcpy(str1, "Hello, world! This is a test string.");
		strcpy(str2, "Hello, world! This is a test string.");

		// Test overlapping regions
		result_original = memmove(str1 + 5, str1, test_sizes[i]);
		result_custom = ft_memmove(str2 + 5, str2, test_sizes[i]);
		if (memcmp(result_original, result_custom, test_sizes[i]) == 0) {
			printf("\033[0;32mOverlapping test successful for size: %zu\033[0m\n", test_sizes[i]);
		} else {
			printf("\033[0;31mOverlapping test failed for size: %zu\033[0m\n", test_sizes[i]);
		}
	}
	printf("\n\n\n");
}

void testing_ft_strlcpy(void) {
	char src[] = "Hello, World!";
	char dest1[20];
	char dest2[20];
	size_t sizes[] = {5, 10, 15, 20};
	size_t result_original, result_custom;

	printf("=== Testing ft_strlcpy ===\n");
	for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
		memset(dest1, 'A', sizeof(dest1)); // Initialisiere dest1 mit 'A' zur Überprüfung des Null-Terminators
		memset(dest2, 'A', sizeof(dest2)); // Initialisiere dest2 mit 'A' zur Überprüfung des Null-Terminators

		result_original = strlcpy(dest1, src, sizes[i]);
		result_custom = ft_strlcpy(dest2, src, sizes[i]);

		if (strcmp(dest1, dest2) == 0 && result_original == result_custom) {
			printf("\033[0;32mTest successful for size: %zu (Original: %zu, Custom: %zu)\033[0m\n", sizes[i], result_original, result_custom);
		} else {
			printf("\033[0;31mTest failed for size: %zu (Original: %zu, Custom: %zu)\033[0m\n", sizes[i], result_original, result_custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_strlcat(void) {
	char dest1[50] = "Hello";
	char dest2[50] = "Hello";
	const char *src = " World!";
	size_t sizes[] = {0, 5, 10, 15, 20, 50};
	size_t result_original, result_custom;

	printf("=== Testing ft_strlcat ===\n");
	for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
		// Reset dest arrays for each test case
		memset(dest1 + 5, 'A', 45); // Fill with 'A' to check null-termination
		dest1[5] = '\0'; // Reset the end of the initial string
		memset(dest2 + 5, 'A', 45); // Same for dest2
		dest2[5] = '\0'; // Reset the end of the initial string

		result_original = strlcat(dest1, src, sizes[i]);
		result_custom = ft_strlcat(dest2, src, sizes[i]);

		if (strcmp(dest1, dest2) == 0 && result_original == result_custom) {
			printf("\033[0;32mTest successful for size: %zu (Original: %zu, Custom: %zu)\033[0m\n", sizes[i], result_original, result_custom);
		} else {
			printf("\033[0;31mTest failed for size: %zu (Original: %zu, Custom: %zu)\033[0m\n", sizes[i], result_original, result_custom);
		}
	}
	printf("\n\n\n");
}

void testing_ft_toupper(void)
{
	char test_chars[] = {'a', 'z', 'A', 'Z', '0', '%', '\n', 127, 'm', 'N'};
	int i;
	char result;
	char expected;

	printf("=== Testing ft_toupper ===\n");
	for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
	{
		result = ft_toupper(test_chars[i]);
		expected = toupper(test_chars[i]);
		if (result == expected)
		{
			printf("\033[0;32mTest successful for: '%c' -> '%c'\033[0m\n", test_chars[i], result);
		}
		else
		{
			printf("\033[0;31mTest failed for: '%c' -> '%c' (Expected: '%c')\033[0m\n", test_chars[i], result, expected);
		}
	}
	printf("\n\n\n");
}

void testing_ft_tolower(void)
{
	char test_chars[] = {'A', 'Z', 'a', 'z', '0', '%', '\n', 127, 'M', 'n'};
	int i;
	char result;
	char expected;

	printf("=== Testing ft_tolower ===\n");
	for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
	{
		result = ft_tolower(test_chars[i]);
		expected = tolower(test_chars[i]);
		if (result == expected)
		{
			printf("\033[0;32mTest successful for: '%c' -> '%c'\033[0m\n", test_chars[i], result);
		}
		else
		{
			printf("\033[0;31mTest failed for: '%c' -> '%c' (Expected: '%c')\033[0m\n", test_chars[i], result, expected);
		}
	}
	printf("\n\n\n");
}

void testing_ft_strchr(void)
{
    const char *test_strings[] = {"Hello, World!", "", "1234567890", "A single character", "\n\t", "abcdefg\0hijklmnop"};
    int test_chars[] = {'W', 'H', '0', 'Z', '\n', 0};
    char *result;
    char *expected;
    int i = 0, j;

    printf("=== Testing ft_strchr ===\n");
    while (i < sizeof(test_strings) / sizeof(test_strings[0]))
    {
        j = 0;
        while (j < sizeof(test_chars) / sizeof(test_chars[0]))
        {
            result = ft_strchr(test_strings[i], test_chars[j]);
            expected = strchr(test_strings[i], test_chars[j]);
            if ((result == expected) || (result && expected && *result == *expected))
            {
                printf("\033[0;32mTest successful for string: \"%s\" with char: '%c' -> Result: '%s'\033[0m\n", test_strings[i], test_chars[j], result ? result : "NULL");
            }
            else
            {
                printf("\033[0;31mTest failed for string: \"%s\" with char: '%c' -> Expected: '%s', Got: %s\033[0m\n", test_strings[i], test_chars[j], expected ? expected : "NULL", result ? result : "NULL");
            }
            j++;
        }
        i++;
    }
    printf("\n\n\n");
}

void testing_ft_strrchr(void)
{
	char *test_str = "Hello, World!";
	char *result;
	char *expected_result;
	int test_char;

	printf("=== Testing ft_strrchr ===\n");

	// Test 1: Suchen eines Zeichens, das vorhanden ist
	test_char = 'o';
	result = ft_strrchr(test_str, test_char);
	expected_result = strrchr(test_str, test_char);
	if (result == expected_result)
		printf("\033[32mTest 1 passed: ft_strrchr(\"%s\", '%c') = %s\033[0m\n", test_str, test_char, result);
	else
		printf("\033[31mTest 1 failed: ft_strrchr(\"%s\", '%c') = %s, expected %s\033[0m\n", test_str, test_char, result, expected_result);

	// Test 2: Suchen des Null-Terminators
	test_char = '\0';
	result = ft_strrchr(test_str, test_char);
	expected_result = strrchr(test_str, test_char);
	if (result == expected_result)
		printf("\033[32mTest 2 passed: ft_strrchr(\"%s\", '%c') = %s\033[0m\n", test_str, '\0', result);
	else
		printf("\033[31mTest 2 failed: ft_strrchr(\"%s\", '%c') = %s, expected %s\033[0m\n", test_str, '\0', result, expected_result);

	// Test 3: Suchen eines Zeichens, das nicht vorhanden ist
	test_char = 'x';
	result = ft_strrchr(test_str, test_char);
	expected_result = strrchr(test_str, test_char);
	if (result == expected_result)
		printf("\033[32mTest 3 passed: ft_strrchr(\"%s\", '%c') = %s\033[0m\n", test_str, test_char, result);
	else
		printf("\033[31mTest 3 failed: ft_strrchr(\"%s\", '%c') = %s, expected %s\033[0m\n", test_str, test_char, result, expected_result);

	printf("\n\n\n");
}

void testing_ft_strncmp(void)
{
    char *s1 = "Hello World";
    char *s2 = "Hello World";
    char *s3 = "Hello world";
    int n = 10;
    int result;
    int expected;

    printf("=== Testing ft_strncmp ===\n");

    // Test 1: Identische Strings
    result = ft_strncmp(s1, s2, n);
    expected = strncmp(s1, s2, n);
    if (result == expected)
        printf("\033[0;32mTest 1 passed: ft_strncmp(\"%s\", \"%s\", %d) = %d, strncmp = %d\033[0m\n", s1, s2, n, result, expected);
    else
        printf("\033[0;31mTest 1 failed: ft_strncmp(\"%s\", \"%s\", %d) = %d, strncmp = %d\033[0m\n", s1, s2, n, result, expected);

    // Test 2: Unterschiedliche Strings
    result = ft_strncmp(s1, s3, n);
    expected = strncmp(s1, s3, n);
    if ((result < 0 && expected < 0) || (result == expected))
        printf("\033[0;32mTest 2 passed: ft_strncmp(\"%s\", \"%s\", %d) = %d, strncmp = %d\033[0m\n", s1, s3, n, result, expected);
    else
        printf("\033[0;31mTest 2 failed: ft_strncmp(\"%s\", \"%s\", %d) = %d, strncmp = %d\033[0m\n", s1, s3, n, result, expected);

    // Test 3: n = 0
    n = 0;
    result = ft_strncmp(s1, s3, n);
    expected = strncmp(s1, s3, n);
    if (result == expected)
        printf("\033[0;32mTest 3 passed: ft_strncmp(\"%s\", \"%s\", %d) = %d, strncmp = %d\033[0m\n", s1, s3, n, result, expected);
    else
        printf("\033[0;31mTest 3 failed: ft_strncmp(\"%s\", \"%s\", %d) = %d, strncmp = %d\033[0m\n", s1, s3, n, result, expected);

    printf("\n\n\n");
}

void testing_ft_memchr(void)
{
	const char str[] = "Example string";
	int c = 'e';
	size_t n = 14;
	void *result;
	void *expected;

	printf("=== Testing ft_memchr ===\n");

	// Test 1: Charakter im String vorhanden
	result = ft_memchr(str, c, n);
	expected = memchr(str, c, n);
	if (result == expected)
		printf("\033[0;32mTest 1 passed: Character '%c' found in \"%s\". ft_memchr = %p, memchr = %p\033[0m\n", c, str, result, expected);
	else
		printf("\033[0;31mTest 1 failed: Character '%c' not correctly found in \"%s\". ft_memchr = %p, memchr = %p\033[0m\n", c, str, result, expected);

	// Test 2: Charakter nicht im String (überprüft die Grenze)
	c = 'z';
	result = ft_memchr(str, c, n);
	expected = memchr(str, c, n);
	if (result == expected)
		printf("\033[0;32mTest 2 passed: Character '%c' not found in \"%s\" as expected. ft_memchr = %p, memchr = %p\033[0m\n", c, str, result, expected);
	else
		printf("\033[0;31mTest 2 failed: Character '%c' incorrectly found in \"%s\". ft_memchr = %p, memchr = %p\033[0m\n", c, str, result, expected);

	// Test 3: Test mit n = 0
	n = 0;
	result = ft_memchr(str, 'e', n);
	expected = memchr(str, 'e', n);
	if (result == expected)
		printf("\033[0;32mTest 3 passed: No search performed with n = 0. ft_memchr = %p, memchr = %p\033[0m\n", result, expected);
	else
		printf("\033[0;31mTest 3 failed: Incorrect behavior with n = 0. ft_memchr = %p, memchr = %p\033[0m\n", result, expected);

	printf("\n\n\n");
}

void testing_ft_memcmp(void)
{
	printf("=== Testing ft_memcmp ===\n");

	// Test 1: Vergleich identischer Strings
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";
	int result = ft_memcmp(str1, str2, 13);
	if (result == 0)
		printf("\033[0;32mTest 1 passed: Identical strings. ft_memcmp = %d\033[0m\n", result);
	else
		printf("\033[0;31mTest 1 failed: Identical strings. ft_memcmp = %d\033[0m\n", result);

	// Test 2: Vergleich unterschiedlicher Strings
	char str3[] = "Hello, World!";
	char str4[] = "Hello, world!";
	result = ft_memcmp(str3, str4, 13);
	if (result != 0)
		printf("\033[0;32mTest 2 passed: Different strings. ft_memcmp = %d\033[0m\n", result);
	else
		printf("\033[0;31mTest 2 failed: Different strings. ft_memcmp = %d\033[0m\n", result);

	// Test 3: Vergleich mit n = 0
	result = ft_memcmp(str1, str2, 0);
	if (result == 0)
		printf("\033[0;32mTest 3 passed: n = 0. ft_memcmp = %d\033[0m\n", result);
	else
		printf("\033[0;31mTest 3 failed: n = 0. ft_memcmp = %d\033[0m\n", result);

	// Test 4: Vergleich der ersten n Bytes, wobei n kleiner als die Stringlänge ist
	result = ft_memcmp(str1, str4, 5); // Vergleicht nur "Hello"
	if (result == 0)
		printf("\033[0;32mTest 4 passed: First n bytes are identical. ft_memcmp = %d\033[0m\n", result);
	else
		printf("\033[0;31mTest 4 failed: First n bytes are identical. ft_memcmp = %d\033[0m\n", result);

	printf("\n\n\n");
}

void testing_ft_strnstr(void)
{
	printf("=== Testing ft_strnstr ===\n");

	char haystack[] = "Hello, World!";
	char needle1[] = "World";
	char needle2[] = "world";
	char needle3[] = "";
	char needle4[] = "!";
	size_t len = strlen(haystack);
	char *result;
	char *expected;

	// Test 1: Needle is found in the haystack
	result = ft_strnstr(haystack, needle1, len);
	expected = strnstr(haystack, needle1, len);
	if (result == expected)
		printf("\033[0;32mTest 1 passed: Needle '%s' found in '%s'. Result: %s\033[0m\n", needle1, haystack, result);
	else
		printf("\033[0;31mTest 1 failed: Needle '%s' not correctly found in '%s'. Expected: %s, Got: %s\033[0m\n", needle1, haystack, expected, result);

	// Test 2: Needle is not found due to case sensitivity
	result = ft_strnstr(haystack, needle2, len);
	expected = strnstr(haystack, needle2, len);
	if (result == expected)
		printf("\033[0;32mTest 2 passed: Needle '%s' correctly not found in '%s'.\033[0m\n", needle2, haystack);
	else
		printf("\033[0;31mTest 2 failed: Needle '%s' incorrectly found in '%s'. Expected: %s, Got: %s\033[0m\n", needle2, haystack, expected, result);

	// Test 3: Empty needle
	result = ft_strnstr(haystack, needle3, len);
	expected = strnstr(haystack, needle3, len);
	if (result == expected)
		printf("\033[0;32mTest 3 passed: Empty needle returns haystack: %s\033[0m\n", result);
	else
		printf("\033[0;31mTest 3 failed: Empty needle does not return haystack correctly. Expected: %s, Got: %s\033[0m\n", expected, result);

	// Test 4: Needle at the end of haystack
	result = ft_strnstr(haystack, needle4, len);
	expected = strnstr(haystack, needle4, len);
	if (result == expected)
		printf("\033[0;32mTest 4 passed: Needle '%s' found at the end of '%s'. Result: %s\033[0m\n", needle4, haystack, result);
	else
		printf("\033[0;31mTest 4 failed: Needle '%s' not correctly found at the end of '%s'. Expected: %s, Got: %s\033[0m\n", needle4, haystack, expected, result);

	// Test 5: Searching beyond the length of haystack
	result = ft_strnstr(haystack, needle1, 8); // Intentionally small length
	expected = strnstr(haystack, needle1, 8);
	if (result == expected)
		printf("\033[0;32mTest 5 passed: Needle '%s' not found when searching only the first 8 characters of '%s'.\033[0m\n", needle1, haystack);
	else
		printf("\033[0;31mTest 5 failed: Incorrect result when searching only the first 8 characters of '%s' for '%s'. Expected: %s, Got: %s\033[0m\n", haystack, needle1, expected, result);

	printf("\n\n\n");
}
void testing_ft_atoi(void)
{
	printf("=== Testing ft_atoi ===\n");

	// Test cases
	char *test_strings[] = {
		"42",           // Standard case
		"-42",          // Negative number
		"0",            // Zero
		"+42",          // Positive sign
		"   42",        // Leading spaces
		"42abc",        // Trailing characters
		"-0",           // Negative zero
		"2147483647",   // INT_MAX
		"-2147483648",  // INT_MIN
		"9999999999",   // Overflow
		"-9999999999",  // Underflow
		"+-42",         // Invalid format
		"++42",         // Invalid format
		"--42"          // Invalid format
	};

	int expected;
	int result;
	int test_passed;
	for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++)
	{
		result = ft_atoi(test_strings[i]);
		expected = atoi(test_strings[i]);
		test_passed = (result == expected);

		if (test_passed)
		{
			printf("\033[0;32mTest passed: '%s' -> %d (Expected: %d)\033[0m\n", test_strings[i], result, expected);
		}
		else
		{
			printf("\033[0;31mTest failed: '%s' -> %d (Expected: %d)\033[0m\n", test_strings[i], result, expected);
		}
	}

	printf("\n\n\n");
}

void testing_ft_calloc(void)
{
    printf("=== Testing ft_calloc ===\n");

    // Scenario 1: Allocate memory for an array of 5 integers
    size_t nmemb1 = 5, size1 = sizeof(int);
    int *ptr1 = ft_calloc(nmemb1, size1);
    int *original_ptr1 = calloc(nmemb1, size1);
    for (size_t i = 0; i < nmemb1; i++)
    {
        if (ptr1[i] != original_ptr1[i])
        {
            printf("\033[0;31mTest 1 failed: Memory content mismatch at index %zu\033[0m\n", i);
            break;
        }
    }
    printf("\033[0;32mTest 1 passed: Memory content matches\033[0m\n");

    // Scenario 2: Allocate memory for an array of 10 chars
    size_t nmemb2 = 10, size2 = sizeof(char);
    char *ptr2 = ft_calloc(nmemb2, size2);
    char *original_ptr2 = calloc(nmemb2, size2);
    for (size_t i = 0; i < nmemb2; i++)
    {
        if (ptr2[i] != original_ptr2[i])
        {
            printf("\033[0;31mTest 2 failed: Memory content mismatch at index %zu\033[0m\n", i);
            break;
        }
    }
    printf("\033[0;32mTest 2 passed: Memory content matches\033[0m\n");

    // Scenario 3: Allocate memory for an array of 0 elements of size 0 (should not fail)
    size_t nmemb3 = 0, size3 = 0;
    void *ptr3 = ft_calloc(nmemb3, size3);
    void *original_ptr3 = calloc(nmemb3, size3);
    if ((ptr3 == NULL && original_ptr3 != NULL) || (ptr3 != NULL && original_ptr3 == NULL))
    {
        printf("\033[0;31mTest 3 failed: One function returned NULL while the other did not\033[0m\n");
    }
    else
    {
        printf("\033[0;32mTest 3 passed: Both functions handled zero allocation correctly\033[0m\n");
    }

    free(ptr1);
    free(original_ptr1);
    free(ptr2);
    free(original_ptr2);
    free(ptr3);
    free(original_ptr3);
    printf("\n\n\n");
}

void testing_ft_strdup(void)
{
	char *test1 = "Hello, World!";
	char *result;
	char *expected;

	printf("=== Testing ft_strdup ===\n");

	// Test 1: Standard string
	result = ft_strdup(test1);
	expected = strdup(test1);
	if (strcmp(result, expected) == 0)
		printf("\033[0;32m[PASS]\033[0m Test 1: Original = \"%s\", ft_ = \"%s\"\n", expected, result);
	else
		printf("\033[0;31m[FAIL]\033[0m Test 1: Original = \"%s\", ft_ = \"%s\"\n", expected, result);
	free(result);
	free(expected);

	// Test 2: Empty string
	result = ft_strdup("");
	expected = strdup("");
	if (strcmp(result, expected) == 0)
		printf("\033[0;32m[PASS]\033[0m Test 2: Original = \"%s\", ft_ = \"%s\"\n", expected, result);
	else
		printf("\033[0;31m[FAIL]\033[0m Test 2: Original = \"%s\", ft_ = \"%s\"\n", expected, result);
	free(result);
	free(expected);

	 //Test 3: NULL pointer (Undefined behavior - just for demonstration, might crash)
	 //This test is commented out because it's undefined behavior and might crash your program.
	// result = ft_strdup(NULL);
	// expected = strdup(NULL);
	// printf("Test 3: Original = \"%s\", ft_ = \"%s\"\n", expected, result);

	printf("\n\n\n");
}

void	test_ft_substr(void)
{
	char *result;

	// Test 1: Normaler Fall
	result = ft_substr("Hello World", 6, 5);
	if (strcmp(result, "World") == 0)
		printf("Test 1 erfolgreich: %s\n", result);
	else
		printf("Test 1 fehlgeschlagen: %s\n", result);
	free(result); // Speicher freigeben

	// Test 2: Startindex außerhalb des Strings
	result = ft_substr("Hello", 10, 3);
	if (result[0] == '\0') // Erwartet wird ein leerer String
		printf("Test 2 erfolgreich: %s\n", result);
	else
		printf("Test 2 fehlgeschlagen: %s\n", result);
	free(result);

	// Test 3: Längere Länge als der String nach Start
	result = ft_substr("Hello", 2, 10);
	if (strcmp(result, "llo") == 0)
		printf("Test 3 erfolgreich: %s\n", result);
	else
		printf("Test 3 fehlgeschlagen: %s\n", result);
	free(result);

	// Weitere Tests können hier hinzugefügt werden...
}

int main(void)
{
	test_ft_substr();
	return 0;
}



int	main(void)
{
	printf("Part 1\n");
	testing_ft_isalpha();
	testing_ft_isdigit();
	testing_ft_isalnum();
	testing_ft_isascii();
	testing_ft_isprint();
	testing_ft_strlen();
	testing_ft_memset();
	testing_ft_bzero();
	testing_ft_memcpy();
	testing_ft_memmove();
	testing_ft_strlcpy();
	testing_ft_strlcat();
	testing_ft_toupper();
	testing_ft_tolower();
	testing_ft_strchr();
	testing_ft_strrchr();
	testing_ft_strncmp();
	testing_ft_memchr();
	testing_ft_memcmp();
	testing_ft_strnstr();
	testing_ft_atoi();
	printf("_________________\n\nAll functions wihout external libraries tested \n_________________\n");
	testing_ft_calloc();
	testing_ft_strdup();
	printf("Part 2\n");
}

