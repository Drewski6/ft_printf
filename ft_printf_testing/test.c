#include "../ft_printf_working/libft/includes/libft.h"
int main (void)
{
	char *new;
	char *message;

	message = ft_strdup("hi there");
	

	new = ft_strjoin("hi", "how are you?");
	printf("%s\n", new);

	free(message);
	free(new);

	return (0);
}
