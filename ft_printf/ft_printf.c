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

/*  *** format_switch (format switch) ***
 *
 *  Acts as a switch statement that determines which function to call
 *  Based on the format specifier used in ft_printf.
 *	Takes the character after a % from input string s in function ft_printf
 *	Takes va_list pointer 'parg'.
 *	Runs va_arg macro to get the next item in va_list. At this point we know
 *	the type thanks to the switch statement.
 *	Returns integer 1 on success.
 */

static int	format_switch(char c, va_list parg)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(parg, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(parg, char *), 1);
	//else if (c == 'p')
	else if (c == 'd')
		ft_putnbr_fd(va_arg(parg, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(parg, int), 1);
	//else if (c == 'u')
	//else if (c == 'x')
	//else if (c == 'X')
	//else if (c == '%')
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

int ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	parg;

	i = 0;
	va_start(parg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			format_switch(s[i + 1], parg);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(parg);
	return (i);
}
