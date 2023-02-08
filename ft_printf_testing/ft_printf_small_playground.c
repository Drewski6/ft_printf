#include "../ft_printf_working/includes/bonus/ft_printf_bonus.h"
#include <stdio.h>

int main (void)
{
	ft_printf("function,output,return\n");
	printf(",%d\n", printf("printf   ,%10c", 'W'));
	ft_printf(",%d\n", ft_printf("ft_printf,%10c", 'W'));
	//printf(" %-1c %-2c %-3c ", '0', 0, '1');
	//ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');


	return (0);
}
