#include "ft_printf.h"
#include <stdio.h>

void test_simple_string(void) {
    char *test_string = "Test";
    int x = printf("Original printf: %s\n", test_string);
    int y = ft_printf("ft_printf: %s\n", test_string);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_integer(void) {
    int test_int = -4264786;
    int x = printf("Original printf: %d\n", test_int);
    int y = ft_printf("ft_printf: %d\n", test_int);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_unsigned_integer(void) {
    unsigned int test_unsigned_int = 42345;
    int x = printf("Original printf: %u\n", test_unsigned_int);
    int y = ft_printf("ft_printf: %u\n", test_unsigned_int);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_pointer(void) {
    int test_int;
    void *test_ptr = &test_int;
    int x = printf("Original printf: %p\n", test_ptr);
    int y = ft_printf("ft_printf: %p\n", test_ptr);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_hexadecimal_lowercase(void) {
    unsigned int test_unsigned_int = 42345;
    int x = printf("Original printf: %x\n", test_unsigned_int);
    int y = ft_printf("ft_printf: %x\n", test_unsigned_int);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_hexadecimal_uppercase(void) {
    unsigned int test_unsigned_int = 42345;
    int x = printf("Original printf: %X\n", test_unsigned_int);
    int y = ft_printf("ft_printf: %X\n", test_unsigned_int);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_percentage_sign(void) {
    int x = printf("Original printf: %%\n");
    int y = ft_printf("ft_printf: %%\n");
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_integer_with_i(void) {
    int test_int = -4264786;
    int x = printf("Original printf: %i\n", test_int);
    int y = ft_printf("ft_printf: %i\n", test_int);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_character(void) {
    char test_char = 'A';
    int x = printf("Original printf: %c\n", test_char);
    int y = ft_printf("ft_printf: %c\n", test_char);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_all_in_one_string(void) {
    char *test_string = "Test";
    int test_int = -4264786;
    unsigned int test_unsigned_int = 42345;
    void *test_ptr = &test_int;
    printf("returnvalue original: %i\n", printf("Original printf: \nString: %s\nInteger: %d\nUnsigned Integer: %u\nPointer: %p\nHexadecimal (lowercase): %x\nHexadecimal (uppercase): %X\nPercent sign: %%\n",
           test_string, test_int, test_unsigned_int, test_ptr, test_unsigned_int, test_unsigned_int));
    ft_printf("returnvalue custom: %i\n", ft_printf("ft_printf: \nString: %s\nInteger: %d\nUnsigned Integer: %u\nPointer: %p\nHexadecimal (lowercase): %x\nHexadecimal (uppercase): %X\nPercent sign: %%\n",
              test_string, test_int, test_unsigned_int, test_ptr, test_unsigned_int, test_unsigned_int));
}

int main(void) {
    printf("\033[0;32mTesting ft_printf...\033[0m\n\n");
    test_simple_string();
    test_integer();
    test_unsigned_integer();
    test_pointer();
    test_hexadecimal_lowercase();
    test_hexadecimal_uppercase();
    test_percentage_sign();
    test_integer_with_i();
    test_character();
    test_all_in_one_string();
    return 0;
}
