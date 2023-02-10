#include "../ft_printf_working/includes/bonus/ft_printf_bonus.h"
#include <stdio.h>

int main (void)
{
	ft_printf("function,output,return\n");
	printf(",%d\n", printf("printf   :[%d]", 1234));
	ft_printf(",%d\n", ft_printf("ft_printf:[%18.3-d]", 1234));

	return (0);
}
