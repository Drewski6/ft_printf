#include <stdio.h>

int main (void)
{
	char	*pointer;

	printf("----- printf without # -----\n");
	printf("c:\t%c\n", 'c');
	printf("s:\t%s\n", "string");
	printf("p:\t%p\n", &pointer);
	printf("d:\t%d\n", 1234);
	printf("i:\t%i\n", 1234);
	printf("u:\t%u\n", 1234);
	printf("x:\t%x\n", 1234);
	printf("X:\t%X\n", 1234);
	printf("%%:\t%%\n\n");

	printf("----- printf with # -----\n");
	printf("c:\t%#c\n", 'c');
	printf("s:\t%#s\n", "string");
	printf("p:\t%#p\n", &pointer);
	printf("d:\t%#d\n", 1234);
	printf("i:\t%#i\n", 1234);
	printf("u:\t%#u\n", 1234);
	printf("x:\t%#x\n", 1234);
	printf("X:\t%#X\n", 1234);
	printf("%%:\t%%\n\n");

	# NOTE: the pound sign is only used for %x and %X



	return 0;
}
