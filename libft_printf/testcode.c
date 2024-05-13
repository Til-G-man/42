#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void test_string(void)
{
	printf("testing String:\n");
	char *test_string[] = {"Hallo das sit ein teststr", "%", "", " ", NULL};
	int i = 0;
	char *RED = "\033[31m";
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";
	int	x;
	int	y;
	while (test_string[i])
	{
		printf("%sTest %i\nOriginal: ",RESET, i);
		x = printf("%s\n", test_string[i]);
		printf("custom:   ");
		fflush(stdout);
		y = ft_printf("%s\n", test_string[i]);
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong for string '%s%s%s':\noriginal: %d\ncustom: %d",RED, RESET, test_string[i], RED, x, y);
		printf("%s\n__________________________________________\n", RESET);
		fflush(stdout);
		i++;
	}
	//special 1
		printf("%sTest %i\nOriginal: ",RESET, i++);
		x = printf("' %s'", "");
		printf("\ncustom:   ");
		fflush(stdout);
		y = ft_printf("' %s'", "");
		printf("\n");
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong for string:\noriginal: %d\ncustom: %d",RED, x, y);
		printf("%s\n__________________________________________\n", RESET);
	//special 2
		printf("%sTest %i\nOriginal: ",RESET, i++);
		x = printf("' %s %s '", " - ", "");
		printf("\ncustom:   ");
		fflush(stdout);
		y = ft_printf("' %s %s '", " - ", "");
		printf("\n");
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong for string:\noriginal: %d\ncustom: %d",RED, x, y);
		printf("%s\n__________________________________________\n", RESET);
	//special 3
		printf("%sTest %i\nOriginal: ",RESET, i++);
		x = printf("' %s %s %s %s %s '", " - ", "", "4", "", "2 ");
		printf("\ncustom:   ");
		fflush(stdout);
		y = ft_printf("' %s %s %s %s %s '", " - ", "", "4", "", "2 ");
		printf("\n");
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong for string:\noriginal: %d\ncustom: %d",RED, x, y);
		printf("%s\n__________________________________________\n", RESET);

	//special 4
		printf("%sTest %i\nOriginal: ",RESET, i++);
		x = printf(" NULL %s NULL ", NULL);
		printf("\ncustom:   ");
		fflush(stdout);
		y = ft_printf(" NULL %s NULL ", NULL);
		printf("\n");
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong for string:\noriginal: %d\ncustom: %d", RED, x, y);
		printf("%s\n__________________________________________\n", RESET);

	printf("\n\n\n");
}


void test_integer(void) {
    int test_int = -4264786;
    int x = printf("Original printf: %d\n", test_int);
    int y = ft_printf("ft_printf: %d\n", test_int);
    printf("return original: %d\nreturn custom: %d\n\n", x, y);
}

void test_unsigned_integer(void) {
	printf("Testing Unsigned Int:\n");
	char *test_int[] = {1, 42, -1, 0, INT_MIN, INT_MAX, LONG_MAX, LONG_MIN, ULONG_MAX, LONG_MAX + 1, UINT_MAX, UINT_MAX + 1};
	int i = 0;
	char *RED = "\033[31m";
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";
	int	x;
	int	y;
	while (test_int[i])
	{
		printf("%sTest %i\nOriginal: ",RESET, i);
		x = printf("%u\n", test_int[i]);
		printf("custom:   ");
		fflush(stdout);
		y = ft_printf("%u\n", test_int[i]);
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong for string '%s%s%s':\noriginal: %d\ncustom: %d",RED, RESET, test_int[i], RED, x, y);
		printf("%s\n__________________________________________\n", RESET);
		fflush(stdout);
		i++;
	}
}

void test_pointer(void) {
	int i = 0;
	char *RED = "\033[31m";
	char *GREEN = "\033[32m";
	char *RESET = "\033[0m";
	int	x;
	int	y;
	//special 1
		printf("%sTest %i\nOriginal: ",RESET, i++);
		x = printf(" %p %p ", 0, 0);
		printf("\ncustom:   ");
		fflush(stdout);
		y = ft_printf(" %p %p ", 0, 0);
		printf("\n");
		if (x == y)
			printf("%soutput the same: org: %d, cus: %d", GREEN, x, y);
		else
			printf("%soutput wrong:\noriginal: %d\ncustom: %d", RED, x, y);
		printf("%s\n__________________________________________\n", RESET);
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

void custom_test (void)
{
	printf("testing custom_test:\n");
	printf("returnvalue original: %i\n",printf(" NULL %s NULL ", NULL));
	printf("returnvalue custom: %i\n",ft_printf(" NULL %s NULL ", NULL));
	//printf("returnvalue custom: %i\n",ft_printf("%%% a"));
	//printf("\n\n\n");
}

/*
check:
%%%
%.
%\0
%w
*/


int main(void) {
    printf("Testing ft_printf...\n\n");
    //test_string();
    //test_integer();
    test_unsigned_integer();
    //test_pointer();
    //test_hexadecimal_lowercase();
    //test_hexadecimal_uppercase();
    //test_percentage_sign();
    //test_integer_with_i();
    //test_character();
    //test_all_in_one_string();
	//custom_test();
    return 0;
}
