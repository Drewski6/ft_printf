/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:41:27 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:41:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	*** ft_dec_to_hex_upper_fd (42 decimal to hexidecimal uppercase fd) ***
 *
 *	Takes an integer 'n' and writes its hexadecimal representation to
 *	file descriptor.
 */

void	ft_dec_to_hex_upper_fd(unsigned int n, int fd, int *print_count)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl / 16 != 0)
		ft_dec_to_hex_upper_fd(nbl / 16, fd, print_count);
	if (nbl % 16 > 9)
		c = ((nbl % 16) + 55);
	else
		c = ((nbl % 16) + '0');
	write(fd, &c, 1);
	(*print_count)++;
	return ;
}

/*	*** ft_dec_to_hex_lower_fd (42 decimal to hexidecimal lowercase fd) ***
 *
 *	Takes an integer 'n' and writes its hexadecimal representation to
 *	file descriptor.
 */

void	ft_dec_to_hex_lower_fd(unsigned int n, int fd, int *print_count)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl / 16 != 0)
		ft_dec_to_hex_lower_fd(nbl / 16, fd, print_count);
	if (nbl % 16 > 9)
		c = ((nbl % 16) + 87);
	else
		c = ((nbl % 16) + '0');
	write(fd, &c, 1);
	(*print_count)++;
	return ;
}

/*	*** ft_p_to_hex_fd (42 pointer to hexidecimal file d) ***
 *
 *	Takes a void pointer, casts it to an unsigned long long and
 *	recursively calls ft_p_to_hex_fd to print address as hexidecimal to
 *	file descriptor.
 *	Returns nothing.
 */

void	ft_p_to_hex_fd(void *p, int fd, int *print_count)
{
	unsigned long long	nbl;
	char				c;

	nbl = (unsigned long long)p;
	if (nbl / 16 != 0)
		ft_p_to_hex_fd((void *)(nbl / 16), fd, print_count);
	if (nbl % 16 > 9)
		c = ((nbl % 16) + 87);
	else
		c = ((nbl % 16) + '0');
	write(fd, &c, 1);
	(*print_count)++;
	return ;
}

/*	*** ft_putunbr_fd (42 put unsigned number file descriptor) ***
 *
 *	Takes a number and prints as an unsigned integer to file descriptor.
 */

void	ft_putunbr_fd(unsigned int n, int fd, int *print_count)
{
	unsigned long	nbl;
	char			c;

	nbl = (unsigned long)n;
	if (nbl / 10 != 0)
		ft_putunbr_fd(nbl / 10, fd, print_count);
	c = (nbl % 10 + '0');
	write(fd, &c, 1);
	(*print_count)++;
	return ;
}
