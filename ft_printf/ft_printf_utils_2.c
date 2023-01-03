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

/*	*** ft_dec_to_hex_upper (42 decimal to hexidecimal uppercase) ***
 *
 *	Takes an integer 'n' and writes its hexadecimal representation to
 *	file descriptor.
 */

void	ft_dec_to_hex_upper(int n, int fd)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl < 0)
		write(fd, "-", 1);
	if (nbl / 16 != 0)
	{
		if (nbl < 0)
			ft_dec_to_hex_upper((nbl / 16) * -1, fd);
		else
			ft_dec_to_hex_upper(nbl / 16, fd);
	}
	if (nbl < 0)
		if (nbl % 16 > 9)
			c = (((nbl % 16) * -1) + 55);
		else
			c = (((nbl % 16) * -1) + '0');
	else
		if (nbl % 16 > 9)
			c = ((nbl % 16) + 55);
		else
			c = ((nbl % 16) + '0');
	write(fd, &c, 1);
	return ;
}

/*	*** ft_dec_to_hex_lower (42 decimal to hexidecimal lowercase) ***
 *
 *	Takes an integer 'n' and writes its hexadecimal representation to
 *	file descriptor.
 */

void	ft_dec_to_hex_lower(int n, int fd)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl < 0)
		write(fd, "-", 1);
	if (nbl / 16 != 0)
	{
		if (nbl < 0)
			ft_dec_to_hex_lower((nbl / 16) * -1, fd);
		else
			ft_dec_to_hex_lower(nbl / 16, fd);
	}
	if (nbl < 0)
		if (nbl % 16 > 9)
			c = (((nbl % 16) * -1) + 55);
		else
			c = (((nbl % 16) * -1) + '0');
	else
		if (nbl % 16 > 9)
			c = ((nbl % 16) + 87);
		else
			c = ((nbl % 16) + '0');
	write(fd, &c, 1);
	return ;
}
