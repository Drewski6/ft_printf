#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *sample;

	sample = (char *)malloc(sizeof(char) * 12);

	printf(" %d\n", printf("%c", '0'));
	printf(" %d\n", printf("Testing character: %c", '0'));
	printf(" %d\n", printf("Testing string: %s", "Here is a test string."));
	printf(" %d\n", printf("Testing decimal: %d", 12345));
	printf(" %d\n", printf("Testing integer: %i", 67890));
	printf(" %d\n", printf("Testing percent: %%"));
	printf(" %d\n", printf("Testing hexidecimal lower: %x", 1234));
	printf(" %d\n", printf("Testing hexidecimal upper: %X", 1234));
	printf(" %d\n", printf("Testing pointer: %p", (void *)sample));
	printf(" %d\n", printf("Testing unsigned decimal: %u", -12345));
	printf(" %d\n", printf(" NULL %s NULL ", NULL));

	free(sample);
	return (0);
}
