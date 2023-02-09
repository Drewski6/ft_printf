#include "../ft_printf_working/includes/bonus/ft_printf_bonus.h"
#include <stdio.h>

int main (void)
{
	ft_printf("function,output,return\n");
	printf(",%d\n", printf("printfs   ,%.5s", "string"));
	printf(",%d\n", printf("printfd   ,%+.5d", 12341234));
	ft_printf(",%d\n", ft_printf("ft_printfs,%.5s", "string"));
	ft_printf(",%d\n", ft_printf("ft_printfd,%+.5d", 12341234));
	printf(",%d\n", printf("pritnf11   : %.5d ", -1));
	printf(",%d\n", printf("pritnf12   : %.5d ", 1));
	ft_printf(",%d\n", ft_printf("ft_pritnf11: %.5d ", -1));
	ft_printf(",%d\n", ft_printf("ft_pritnf12: %.5d ", 1));

/*
TEST(11, print);
TEST(12, print(" %.2d ", 1));
*/

	return (0);
}
