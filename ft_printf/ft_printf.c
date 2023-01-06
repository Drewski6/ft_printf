/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:22:48 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:22:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	*** ft_pointer_handle (42 pointer handler) ***
 *
 *	Additional function to check NULL status of pointer.
 *	If NULL, prints "(nil)" and returns.
 *	If not NULL, prints the address.
 */

void	ft_pointer_handle(va_list parg, int fd, int *print_count)
{
	void	*ptr;

	ptr = va_arg(parg, void *);
	if (!ptr)
	{
		write(fd, "(nil)", 5);
		*print_count += 5;
	}
	else
	{
		write (fd, "0x", 2);
		*print_count += 2;
		ft_p_to_hex(ptr, fd, print_count);
	}
}

/*  *** format_switch (format switch file descriptor) ***
 *
 *  Acts as a switch statement that determines which function to call
 *  Based on the format specifier used in ft_printf.
 *	Takes the character after a % from input string s in function ft_printf
 *	Takes va_list pointer 'parg'.
 *	Runs va_arg macro to get the next item in va_list. At this point we know
 *	the type thanks to the switch statement.
 *	Also takes a file descriptor.
 *	Returns integer 1 on success.
 */

static int	format_switch_fd(char c, va_list parg, int fd, int *print_count)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(parg, int), fd, print_count);
	else if (c == 's')
		ft_putstr_fd(va_arg(parg, char *), fd, print_count);
	else if (c == 'p')
		ft_pointer_handle(parg, fd, print_count);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(parg, int), fd, print_count);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(parg, int), fd, print_count);
	else if (c == 'u')
		ft_putunbr_fd((unsigned int)va_arg(parg, int), fd, print_count);
	else if (c == 'x')
		ft_dec_to_hex_lower(va_arg(parg, int), fd, print_count);
	else if (c == 'X')
		ft_dec_to_hex_upper(va_arg(parg, int), fd, print_count);
	else if (c == '%')
		ft_putpercent(print_count);
	return (1);
}

/*  *** ft_printf (42 print format) ***
 *
 *  Takes a string followed by a variable number of arguments corresponding
 *  to format specifiers in the string.
 *	Uses a loop to iterate over string. When a % is found, activates a switch
 *	statement function and passes pointer to va_list for further execution.
 *	Returns integer number of character processed from string 's'.
 */

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	parg;
	int		fd;
	int		print_count;

	i = 0;
	fd = 1;
	print_count = 0;
	va_start(parg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			format_switch_fd(s[i + 1], parg, fd, &print_count);
			i++;
		}
		else
		{
			write(fd, &s[i], 1);
			print_count++;
		}
		i++;
	}
	va_end(parg);
	return (print_count);
}
