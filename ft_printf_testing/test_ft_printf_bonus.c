#include "../ft_printf_working/includes/bonus/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// c, s, p, d, i, u, x, X, %

int main (void)
{
	char 	*input = "d:[%%]\n";

	ft_printf(",%d\n", ft_printf("ft_printf"));
	ft_printf("c: %c\n", 'W');
	ft_printf("s: %s\n", "Hey how's it going?");
	ft_printf("p: %p\n", input);
	ft_printf("pos d: %d\n", 1234);
	ft_printf("neg d: %d\n", -1234);
	ft_printf("pos i: %i\n", 1234);
	ft_printf("neg i: %i\n", -1234);
	ft_printf("pos u: %u\n", 1234);
	ft_printf("neg u: %u\n", -1234);
	ft_printf(",%d\n", ft_printf("pos x: %x", 1234));
	ft_printf("neg x: %x\n", -1234);
	ft_printf("pos x: %#x\n", 1234);
	ft_printf("neg x: %#x\n", -1234);
	ft_printf("pos X: %X\n", 1234);
	ft_printf("neg X: %X\n", -1234);
	ft_printf("percent%%end\n");

	printf("\nprintf\n");
	printf("c: %c\n", 'W');
	printf("s: %s\n", "Hey how's it going?");
	printf("p: %p\n", input);
	printf("pos d: %d\n", 1234);
	printf("neg d: %d\n", -1234);
	printf("pos i: %i\n", 1234);
	printf("neg i: %i\n", -1234);
	printf("pos u: %u\n", 1234);
	printf("neg u: %u\n", -1234);
	printf("pos x: %x\n", 1234);
	printf("neg x: %x\n", -1234);
	printf("pos X: %X\n", 1234);
	printf("neg X: %X\n", -1234);
	printf("percent%%end");

	return (0);
}
