/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:53:04 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/22 10:51:35 by tgluckli         ###   ########.fr       */
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
	size_t sizes[] = {5, 10, 15, 20, 50};
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

int	main(void)
{
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
}

