#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	char *sample;

	sample = (char *)malloc(sizeof(char) * 12);

	ft_printf(" %d\n", ft_printf("%c", '0'));
	ft_printf(" %d\n", ft_printf("Testing character: %c", '0'));
	ft_printf(" %d\n", ft_printf("Testing string: %s", "Here is a test string."));
	ft_printf(" %d\n", ft_printf("Testing decimal: %d", 12345));
	ft_printf(" %d\n", ft_printf("Testing integer: %i", 67890));
	ft_printf(" %d\n", ft_printf("Testing percent: %%"));
	ft_printf(" %d\n", ft_printf("Testing hexidecimal lower: %x", 1234));
	ft_printf(" %d\n", ft_printf("Testing hexidecimal upper: %X", 1234));
	ft_printf(" %d\n", ft_printf("Testing pointer: %p", (void *)sample));
	ft_printf(" %d\n", ft_printf("Testing unsigned decimal: %u", -12345));
	ft_printf(" %d\n", ft_printf(" NULL %s NULL ", NULL));

	free(sample);
	return (0);
}
