#include <stdio.h>

int main (void)
{
	char	*pointer;

/*	Testing with -
 *
 *	NOTE:	left justify
 *			this makes the print take up at least x number of spaces after.
 *			Adding a number indicates how large to make the space.
 *			Adding - makes it align to the left rather than default right.
 *			### Works with all ###
 */

	printf("\n***** printf without - *****\n");
	printf("10c:\t---%10c---\n", 'c');
	printf("10s:\t---%10s---\n", "string");
	printf("20p:\t---%20p---\n", &pointer);
	printf("10d:\t---%10d---\n", 1234);
	printf("10i:\t---%10i---\n", 1234);
	printf("10u:\t---%10u---\n", 1234);
	printf("10x:\t---%10x---\n", 1234);
	printf("10X:\t---%10X---\n", 1234);

	printf("\n***** printf with - *****\n");
	printf("-10c:\t---%-10c---\n", 'c');
	printf("-10s:\t---%-10s---\n", "string");
	printf("-20p:\t---%-20p---\n", &pointer);
	printf("-10d:\t---%-10d---\n", 1234);
	printf("-10i:\t---%-10i---\n", 1234);
	printf("-10u:\t---%-10u---\n", 1234);
	printf("-10x:\t---%-10x---\n", 1234);
	printf("-10X:\t---%-10X---\n", 1234);

/*	Testing with 0
 *
 *	NOTE:	Different than a positive number which indicates how much padding to use.
 *			Uses 0 as padding rather than [ SPACE ].
 *			Does not work with - for left justify.
 *			### Cant with work c, s, or p (get a warning but works) ###
 */

	printf("\n***** printf without 0 *****\n");
	printf("10c:\t---%10c---\n", 'c');
	printf("10s:\t---%10s---\n", "string");
	printf("20p:\t---%20p---\n", &pointer);
	printf("10d:\t---%10d---\n", 1234);
	printf("10i:\t---%10i---\n", 1234);
	printf("10u:\t---%10u---\n", 1234);
	printf("10x:\t---%10x---\n", 1234);
	printf("10X:\t---%10X---\n", 1234);

	printf("\n***** printf with 0 *****\n");
	printf("010c:\t---%010c---\n", 'c');
	printf("010s:\t---%010s---\n", "string");
	printf("020p:\t---%020p---\n", &pointer);
	printf("010d:\t---%010d---\n", 1234);
	printf("010i:\t---%010i---\n", 1234);
	printf("010u:\t---%010u---\n", 1234);
	printf("010x:\t---%010x---\n", 1234);
	printf("010X:\t---%010X---\n", 1234);

/*	Testing with .
 *
 *	NOTE:	Specifies the precision for an argument.
 *			Can be used with strings for maxiumum and minimum widths
 *			Adds padding with 0s for most up to 8.
 *			character has left padding of [ SPACE ]	rather than 0s.
 *			Error with c and p	
 *			### IDK this one is hard ###
 */

	printf("\n***** printf without . *****\n");
	printf("c:\t---%c---\n", 'c');
	printf("s:\t---%s---\n", "string");
	printf("p:\t---%p---\n", &pointer);
	printf("d:\t---%d---\n", 1234);
	printf("i:\t---%i---\n", 1234);
	printf("u:\t---%u---\n", 1234);
	printf("x:\t---%x---\n", 1234);
	printf("X:\t---%X---\n", 1234);

	printf("\n***** printf with . *****\n");
	printf("4.8c:\t---%4.8c---\n", 'c');
	printf("4.8s:\t---%4.8s---\n", "this is a long string");
	printf("4.8p:\t---%4.8p---\n", &pointer);
	printf("4.8d:\t---%4.8d---\n", 1234);
	printf("4.8i:\t---%4.8i---\n", 1234);
	printf("4.8u:\t---%4.8u---\n", 1234);
	printf("4.8x:\t---%4.8x---\n", 1234);
	printf("4.8X:\t---%4.8X---\n", 1234);

/*	Testing with #
 *
 *	NOTE:	The pound sign is only used for %x and %X.
 *			### Adds 0x or 0X for %x and %X only ###
 */

	printf("\n***** printf without # *****\n");
	printf("c:\t%c\n", 'c');
	printf("s:\t%s\n", "string");
	printf("p:\t%p\n", &pointer);
	printf("d:\t%d\n", 1234);
	printf("i:\t%i\n", 1234);
	printf("u:\t%u\n", 1234);
	printf("x:\t%x\n", 1234);
	printf("X:\t%X\n", 1234);
	printf("%%:\t%%\n");

	printf("\n***** printf with # *****\n");
	printf("#c:\t%#c\n", 'c');
	printf("#s:\t%#s\n", "string");
	printf("#p:\t%#p\n", &pointer);
	printf("#d:\t%#d\n", 1234);
	printf("#i:\t%#i\n", 1234);
	printf("#u:\t%#u\n", 1234);
	printf("#x:\t%#x\n", 1234);
	printf("#X:\t%#X\n", 1234);
	printf("%%:\t%%\n");

/*	Testing with [ SPACE ]
 *
 *	NOTE:	Positive values begin with a [ SPACE ].
 *			### ONLY works with d and i (p works but compiler gives wanring) ###
 */

	printf("\n***** printf without [ SPACE ] *****\n");
	printf("c:\t---%c---\n", 'c');
	printf("s:\t---%s---\n", "string");
	printf("p:\t---%p---\n", &pointer);
	printf("d:\t---%d---\n", 1234);
	printf("i:\t---%i---\n", 1234);
	printf("u:\t---%u---\n", 1234);
	printf("x:\t---%x---\n", 1234);
	printf("X:\t---%X---\n", 1234);

	printf("\n***** printf with [ SPACE ] *****\n");
	printf(" c:\t---% c---\n", 'c');
	printf(" s:\t---% s---\n", "string");
	printf(" p:\t---% p---\n", &pointer);
	printf(" d:\t---% d---\n", 1234);
	printf(" i:\t---% i---\n", 1234);
	printf(" u:\t---% u---\n", 1234);
	printf(" x:\t---% x---\n", 1234);
	printf(" X:\t---% X---\n", 1234);

/*	Testing with +
 *
 *	NOTE:	Adds the sign after
 *			### Does not work with c, s, p(works but get a compiler warning), u, x, X ###
 */

	printf("\n***** printf without + *****\n");
	printf("10c:\t---%10c---\n", 'c');
	printf("10s:\t---%10s---\n", "string");
	printf("20p:\t---%20p---\n", &pointer);
	printf("10d:\t---%10d---\n", 1234);
	printf("10i:\t---%10i---\n", 1234);
	printf("10u:\t---%10u---\n", 1234);
	printf("10x:\t---%10x---\n", 1234);
	printf("10X:\t---%10X---\n", 1234);

	printf("\n***** printf with + *****\n");
	printf("+10c:\t---%+10c---\n", 'c');
	printf("+10s:\t---%+10s---\n", "string");
	printf("+20p:\t---%+20p---\n", &pointer);
	printf("+10d:\t---%+10d---\n", 1234);
	printf("+10i:\t---%+10i---\n", 1234);
	printf("+10u:\t---%+10u---\n", 1234);
	printf("+10x:\t---%+10x---\n", 1234);
	printf("+10X:\t---%+10X---\n", 1234);

	printf("+10i:\t---%+10i---\n", 1234);
	printf("+10i:\t---%+10i---\n", -1234);

	return 0;
}
