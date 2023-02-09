#include "../ft_printf_working/includes/bonus/ft_printf_bonus.h"
#include <stdio.h>

int main (void)
{
	//ft_printf("function,output,return\n");
	//printf(",%d\n", printf("printf   ,%10c", 'W'));
	//ft_printf(",%d\n", ft_printf("ft_printf,%10c", 'W'));
	printf(" %04d ", -14);
	printf(" %05d ", -15);
	printf(" %06d ", -16);
	ft_printf(" %04d ", -14);
	ft_printf(" %05d ", -15);
	ft_printf(" %06d ", -16);

/*
	TEST(15, print);
 41     TEST(16, print(" %05d ", -15));
 42     TEST(17, print(" %06d ", -16));
*/

	return (0);
}
