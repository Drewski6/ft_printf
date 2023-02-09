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
 *	Called from format_switch to manage printing pointer addresses.
 *	Prints "(nil)" for NULL pointers and full pointer addresses when address
 *	is valid.
 *	Takes t_flags struct pointer and va_list pointer.
 *	Returns 0 on success and -1 on ERROR.
 */

int	ft_pointer_handle(t_flags *seq_info, va_list parg)
{
	void	*ptr;

	ptr = va_arg(parg, void *);
	if (!ptr)
	{
		if (write_to_buf(seq_info, "(nil)", 5, -1) <= 0)
			return (-1);
	}
	else
	{
		if (write_to_buf(seq_info, "0x", 2, -1) <= 0)
			return (-1);
		ft_p_to_hex_buf(ptr, seq_info);
	}
	return (0);
}

/*	*** percent_handler () ***
 *
 *	Once a percent is seen in main string, ft_printf passes control to this
 *	function for managing what to do when a % is found.
 *	Takes address of beginning of sequence 's', and 'parg', 'fd', and 
 *	'print_count' for passthrough to subseq_parser.
 *	Returns 'i' number of bytes parces in main string or -1 on ERROR.
 */

int	percent_handler(char *s, va_list parg, int fd, int *print_count)
{
	int		seq_len;
	int		i;

	i = 0;
	if (s[i] == '%')
	{
		write(fd, "%", 1);
		i++;
		return (i);
	}
	seq_len = subseq_parser(s, parg, fd, print_count);
	if (seq_len < 0)
	{
		va_end(parg);
		return (-1);
	}
	(*print_count)--;
	i += seq_len;
	return (i);
}

/*  *** ft_printf (42 print format) ***
 *
 *	42 project for re-creating printf. 
 *		This bonus project includes working format specifiers and flags
 *	Format Specifiers:
 *		c s p d i u x X %
 *	Flags:
 *		- 0 . # [SPACE] +
 *	Takes a string and uses variadic macros to take unlimited format specifiers.
 *	Returns formatted string printed to standard out.
 *	NOTE: to change file descriptor output from stdout to any fd, add int fd
 *	to definition and replace third parameter in percent_handler to fd, and 
 *	change write(1, &s[i], 1) to write(fd, &s[i], 1)
 */

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	parg;
	int		print_count;
	int		ph_ret;

	i = 0;
	print_count = 0;
	va_start(parg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ph_ret = percent_handler((char *)&s[i + 1], parg, 1, &print_count);
			if (ph_ret < 0)
				return (-1);
			i += ph_ret;
		}
		else
			write(1, &s[i], 1);
		print_count++;
		i++;
	}
	va_end(parg);
	return (print_count);
}
