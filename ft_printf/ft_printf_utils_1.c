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
 *	*** from libft ***
 *
 *  Outputs the character 'c' to file descriptor.
 *  Returns nothing.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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
 *	*** from libft ***
 *
 *  Outputs the string 's' to the given file descriptor.
 *  Returns nothing.
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}

/*  *** ft_putnbr_fd (42 put number file descriptor) ***
 *
 *  Outputs the integer 'n' to the given file descriptor.
 *  Returns nothing.
 */

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl < 0)
		write(fd, "-", 1);
	if (nbl / 10 != 0)
	{
		if (nbl < 0)
			ft_putnbr_fd((nbl / 10) * -1, fd);
		else
			ft_putnbr_fd(nbl / 10, fd);
	}
	if (nbl < 0)
		c = (((nbl % 10) * -1) + '0');
	else
		c = (nbl % 10 + '0');
	write(fd, &c, 1);
	return ;
}

/*	*** ft_putpercent (42 put percent)
 *	*** NOT libft ***
 *
 *	Writes a percent to stdout.
 *	Returns nothing.
 */

 void	ft_putpercent(void)
{
	write(1, "%", 1);
}
