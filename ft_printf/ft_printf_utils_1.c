/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:41:16 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:41:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*  *** ft_putchar_fd (42 put character file descriptor) ***
 *
 *  Outputs the character 'c' to file descriptor.
 *  Returns nothing.
 */

void	ft_putchar_fd(char c, int fd, int *print_count)
{
	write(fd, &c, 1);
	(*print_count)++;
}

/*  *** ft_strlen (42 string length) ***
 *	*** from libft ***
 *
 *  Takes a character pointer.
 *  Returns size_t number of 8 bit memory spaces between input pointer and
 *  the first null terminator.
 */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/*  *** ft_putstr_fd (42 put string file descriptor) ***
 *
 *  Outputs the string 's' to the given file descriptor.
 *  Returns nothing.
 */

void	ft_putstr_fd(char *s, int fd, int *print_count)
{
	size_t	str_len;

	str_len = 0;
	//if (s == 0)
		//return ;
	str_len = ft_strlen(s);
	write(fd, s, str_len);
	(*print_count) += str_len;
}

/*  *** ft_putnbr_fd (42 put number file descriptor) ***
 *
 *  Outputs the integer 'n' to the given file descriptor.
 *  Returns nothing.
 */

void	ft_putnbr_fd(int n, int fd, int *print_count)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl < 0)
	{
		write(fd, "-", 1);
		(*print_count)++;
	}
	if (nbl / 10 != 0)
	{
		if (nbl < 0)
			ft_putnbr_fd((nbl / 10) * -1, fd, print_count);
		else
			ft_putnbr_fd(nbl / 10, fd, print_count);
	}
	if (nbl < 0)
		c = (((nbl % 10) * -1) + '0');
	else
		c = (nbl % 10 + '0');
	write(fd, &c, 1);
	(*print_count)++;
	return ;
}

/*	*** ft_putpercent (42 put percent)
 *
 *	Writes a percent to stdout.
 *	Returns nothing.
 */

 void	ft_putpercent(int *print_count)
{
	write(1, "%", 1);
	(*print_count)++;
}
