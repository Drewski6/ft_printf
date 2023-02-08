/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:22:48 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:22:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** ft_pointer_handle (42 pointer handler) ***
 *
 *	Additional function to check NULL status of pointer.
 *	If NULL, prints "(nil)" and returns.
 *	If not NULL, prints the address.
 */

int	ft_pointer_handle(va_list parg, char **buf)
{
	void	*ptr;

	ptr = va_arg(parg, void *);
	if (!ptr)
	{
		if (write_to_buf(buf, "(nil)", 5, 0) <= 0)
			return (-1);
	}
	else
	{
		if (write_to_buf(buf, "0x", 2, 0) <= 0)
			return (-1);
		ft_p_to_hex_buf(ptr, buf);
	}
	return (0);
}

/*  *** format_switch_buf (format switch file descriptor) ***
 *
 *  Acts as a switch statement that determines which function to call
 *  Based on the format specifier used in ft_printf.
 *	Takes the character after a % from input string s in function ft_printf
 *	Takes va_list pointer 'parg'.
 *	Runs va_arg macro to get the next item in va_list. At this point we know
 *	the type thanks to the switch statement.
 *	Also takes a file descriptor.
 *	Returns integer 1 on success and -1 on error (format specifier not found).
 */

int	format_switch_buf(char c, va_list parg, char **buf)
{
	if (c == 'c')
	{
		if (ft_putchar_buf(va_arg(parg, int), buf))
			return (-1);
	}
	else if (c == 's')
	{
		if (ft_putstr_buf(va_arg(parg, char *), buf))
			return (-1);
	}
	else if (c == 'p')
	{
		if (ft_pointer_handle(parg, buf))
			return (-1);
	}
	else if (c == 'd')
	{
		if (ft_putnbr_buf(va_arg(parg, int), buf))
			return (-1);
	}
	else if (c == 'i')
	{
		if (ft_putnbr_buf(va_arg(parg, int), buf))
			return (-1);
	}
	else if (c == 'u')
	{
		if (ft_putunbr_buf((unsigned int)va_arg(parg, int), buf))
			return (-1);
	}
	else if (c == 'x')
	{
		if (ft_dec_to_hex_lower_buf(va_arg(parg, int), buf))
			return (-1);
	}
	else if (c == 'X')
	{
		if (ft_dec_to_hex_upper_buf(va_arg(parg, int), buf))
			return (-1);
	}
	else
		return (-1);
	return (0);
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
	int		seq_len;

	i = 0;
	fd = 1;
	print_count = 0;
	va_start(parg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
			{
				write(fd, "%", 1);
				print_count++;
				i += 2;
				continue ;
			}
			seq_len = subsequence_parser(&s[i + 1], parg, fd, &print_count);
			if (seq_len < 0)
			{
				va_end(parg);
				return (-1);
			}
			i += seq_len;
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
