#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *sample;

	sample = (char *)malloc(sizeof(char) * 12);

	printf("Testing character: %c\n", 'W');
	printf("Testing string: %s\n", "Here is a test string.");
	printf("Testing decimal: %d\n", 12345);
	printf("Testing integer: %i\n", 67890);
	printf("Testing percent: %%\n");
	printf("Testing hexidecimal lower: %x\n", 1234);
	printf("Testing hexidecimal upper: %X\n", 1234);
	printf("Testing pointer: %p\n", (void *)sample);
	printf("Testing unsigned decimal: %u\n", -12345);

	free(sample);
	return (0);
}
