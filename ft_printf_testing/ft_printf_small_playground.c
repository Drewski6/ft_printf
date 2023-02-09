#include "../ft_printf_working/includes/bonus/ft_printf_bonus.h"
#include <stdio.h>

int main (void)
{
	//ft_printf("function,output,return\n");
	//printf(",%d\n", printf("printf   ,%10c", 'W'));
	//ft_printf(",%d\n", ft_printf("ft_printf,%10c", 'W'));
	printf("printf: %#x \n", 0);
	ft_printf("ft_printf: %#x \n", 0);

/*
TEST(1, print(" %#x ", 0));
TEST(25, print(" %#x ", LONG_MIN));
TEST(29, print(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, U
LONG_MAX, 0, -42));
TEST(31, print(" %#X ", 0));
TEST(55, print(" %#X ", LONG_MIN));
TEST(59, print(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/

	return (0);
}
