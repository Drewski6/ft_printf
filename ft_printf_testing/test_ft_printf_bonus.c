#include "../ft_printf_working/b_includes/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int main (void)
{
	char	*sample;
	char	*sample_n;

	sample = (char *)malloc(sizeof(char) * 12);
	sample_n = NULL;

	// Working
	ft_printf("*** Working ***\n");
	ft_printf(" %d\n", ft_printf("%c", '0'));
	ft_printf(" %d\n", ft_printf("Testing character: %c", '0'));
	ft_printf(" %d\n", ft_printf("Testing string: %s", "Here is a test string."));
	ft_printf(" %d\n", ft_printf("Testing decimal: %d", 12345));
	ft_printf(" %d\n", ft_printf("Testing integer: %i", 67890));
	ft_printf(" %d\n", ft_printf("Testing percent: %%"));
	ft_printf(" %d\n", ft_printf("Testing hexidecimal lower: %x", 1234));
	ft_printf(" %d\n", ft_printf("Testing hexidecimal lower: %x", -1234));
	ft_printf(" %d\n", ft_printf("Testing hexidecimal upper: %X", 1234));
	ft_printf(" %d\n", ft_printf("Testing unsigned decimal: %u", -12345));
	ft_printf(" %d\n", ft_printf("Testing ft_pointer: %p", (void *)sample));
	//	printf(" %d\n", printf("Testing    pointer: %p", (void *)sample));
	ft_printf(" %d\n", ft_printf("Testing ft_pointer: %p", (void *)sample_n));
	//	printf(" %d\n", printf("Testing    pointer: %p", (void *)sample_n));
	ft_printf(" %d\n", ft_printf(" NULL %s NULL ", NULL));
	//printf(" %d\n", printf(" NULL %s NULL ", NULL));

	// Issues
	ft_printf("\n*** Issues ***\n");

	free(sample);
	return (0);
}
