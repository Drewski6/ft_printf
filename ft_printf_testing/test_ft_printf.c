#include "../ft_printf/ft_printf.h"

int main (void)
{
	ft_printf("Testing character: %c\n", 'W');
	ft_printf("Testing string: %s\n", "Here is a test string.");
	ft_printf("Testing decimal: %d\n", 12345);
	ft_printf("Testing integer: %i\n", 67890);

	return (0);
}
