/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:20:35 by tilman            #+#    #+#             */
/*   Updated: 2024/05/04 15:39:35 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*test_string = "Test";
	int		test_int = 42;
	unsigned int test_unsigned_int = 42;
	void	*test_ptr = &test_int;

	printf("\033[0;32mTesting ft_printf...\033[0m\n");

	// Test 1: Einfacher String
	printf("Original printf: ");
	printf("%s\n", test_string);
	printf("ft_printf:       ");
	ft_printf("%s\n", test_string);

	// Test 2: Integer
	printf("Original printf: ");
	printf("%d\n", test_int);
	printf("ft_printf:       ");
	ft_printf("%d\n", test_int);

	// Test 3: Unsigned Integer
	printf("Original printf: ");
	printf("%u\n", test_unsigned_int);
	printf("ft_printf:       ");
	ft_printf("%u\n", test_unsigned_int);

	// Test 4: Pointer
	printf("Original printf: ");
	printf("%p\n", test_ptr);
	printf("ft_printf:       ");
	ft_printf("%p\n", test_ptr);

	// Test 5: Hexadezimal klein
	printf("Original printf: ");
	printf("%x\n", test_unsigned_int);
	printf("ft_printf:       ");
	ft_printf("%x\n", test_unsigned_int);

	// Test 6: Hexadezimal groß
	printf("Original printf: ");
	printf("%X\n", test_unsigned_int);
	printf("ft_printf:       ");
	ft_printf("%X\n", test_unsigned_int);

	// Test 7: Prozentzeichen
	printf("Original printf: ");
	printf("%%\n");
	printf("ft_printf:       ");
	ft_printf("%%\n");

	printf("\n\n\n");
}

