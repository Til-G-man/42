/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:20:35 by tilman            #+#    #+#             */
/*   Updated: 2024/05/08 16:03:01 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int x;
	int y;
	char	*test_string = "Test";
	int		test_int = -4264786;
	unsigned int test_unsigned_int = 42345;
	void	*test_ptr = &test_int;

	printf("\033[0;32mTesting ft_printf...\033[0m\n");
	printf("\n\n");
	// Test 1: Einfacher String
	printf("input string:\n");
	printf("Original printf: ");
	x = printf("%s", test_string);
	printf("\nft_printf: ");
	fflush(stdout);
	y = ft_printf("%s", test_string);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	// Test 2: Integer
	printf("input integer:\n");
	printf("Original printf: ");
	x = printf("%d\n", test_int);
	printf("ft_printf: ");
	fflush(stdout);
	y = ft_printf("%d\n", test_int);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	// Test 3: Unsigned Integer
	printf("input unsigned integer:\n");
	printf("Original printf: ");
	x = printf("%u\n", test_unsigned_int);
	printf("ft_printf: ");
	fflush(stdout);
	y = ft_printf("%u\n", test_unsigned_int);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	// Test 4: Pointer
	printf("input pointer:\n");
	printf("Original printf: ");
	x = printf("%p\n", test_ptr);
	printf("ft_printf: ");
	fflush(stdout);
	y = ft_printf("%p\n", test_ptr);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);

	//// Test 4.1: Pointer
	//printf("input pointer:\n");
	//printf("Original printf: ");
	//x = printf("%p %p\n",0, 0);
	//printf("ft_printf: ");
	//fflush(stdout);
	//y = ft_printf("%p %p\n",0, 0);
	//printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	//// Test 5: Hexadezimal klein
	printf("input hexadecimal (lowercase):\n");
	printf("Original printf: ");
	x = printf("%x\n", test_unsigned_int);
	printf("ft_printf: ");
	fflush(stdout);
	y = ft_printf("%x\n", test_unsigned_int);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	// Test 6: Hexadezimal groß
	printf("input hexadecimal (uppercase):\n");
	printf("Original printf: ");
	x = printf("%X\n", test_unsigned_int);
	printf("ft_printf: ");
	fflush(stdout);
	y = ft_printf("%X\n", test_unsigned_int);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	// Test 7: Prozentzeichen
	printf("input percentage sign:\n");
	printf("Original printf: ");
	x = printf("%%\n");
	printf("ft_printf: ");
	fflush(stdout);
	y = ft_printf("%%\n");
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);
	ft_printf("\n\n\n");

	// Test 8: Integer mit %i
	printf("input integer with %%i:\n");
	printf("Original printf: ");
	x = printf("%i\n", test_int);
	fflush(stdout);
	printf("ft_printf: ");
	y = ft_printf("%i\n", test_int);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);

	// Test 9: Integer mit %d
	printf("input integer with %%d:\n");
	printf("Original printf: ");
	x = printf("%d\n", test_int);
	fflush(stdout);
	printf("ft_printf: ");
	y = ft_printf("%d\n", test_int);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);

	// Test 10: Einzelnes Zeichen mit %c
	char test_char = 'A';
	printf("input character with %%c:\n");
	printf("Original printf: ");
	x = printf("%c\n", test_char);
	fflush(stdout);
	printf("ft_printf: ");
	y = ft_printf("%c\n", test_char);
	printf("\nreturn original: %d\nreturn custom: %d\n\n", x, y);

	// test 11

	printf("all in one string:\n");
	printf("returnvalue original: %i\n", printf("Original printf: \nString: %s\nInteger: %d\nUnsigned Integer: %u\nPointer: %p\nHexadecimal (lowercase): %x\nHexadecimal (uppercase): %X\nPercent sign: %%\n",
       test_string, test_int, test_unsigned_int, test_ptr, test_unsigned_int, test_unsigned_int));

	printf("returnvalue custom: %d", ft_printf("ft_printf: \nString: %s\nInteger: %d\nUnsigned Integer: %u\nPointer: %p\nHexadecimal (lowercase): %x\nHexadecimal (uppercase): %X\nPercent sign: %%\n",
          test_string, test_int, test_unsigned_int, test_ptr, test_unsigned_int, test_unsigned_int));

	printf("\n\n\n");
}

