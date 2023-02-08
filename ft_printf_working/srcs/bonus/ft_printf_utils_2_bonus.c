/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:41:27 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:41:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** ft_dec_to_hex_upper_fd (42 decimal to hexidecimal uppercase fd) ***
 *
 *	Takes an integer 'n' and writes its hexadecimal representation to
 *	file descriptor.
 */

int	ft_dec_to_hex_upper_buf(unsigned int n, t_flags *seq_info)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl / 16 != 0)
	{
		if (ft_dec_to_hex_upper_buf(nbl / 16, seq_info))
			return (-1);
	}
	if (nbl % 16 > 9)
		c = ((nbl % 16) + 55);
	else
		c = ((nbl % 16) + '0');
	if (write_to_buf(seq_info, &c, 1, -1) <= 0)
		return (-1);
	return (0);
}

/*	*** ft_dec_to_hex_lower_fd (42 decimal to hexidecimal lowercase fd) ***
 *
 *	Takes an integer 'n' and writes its hexadecimal representation to
 *	file descriptor.
 */

int	ft_dec_to_hex_lower_buf(unsigned int n, t_flags *seq_info)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl / 16 != 0)
	{
		if (ft_dec_to_hex_lower_buf(nbl / 16, seq_info))
			return (-1);
	}
	if (nbl % 16 > 9)
		c = ((nbl % 16) + 87);
	else
		c = ((nbl % 16) + '0');
	if (write_to_buf(seq_info, &c, 1, -1) <= 0)
		return (-1);
	return (0);
}

/*	*** ft_p_to_hex_fd (42 pointer to hexidecimal file d) ***
 *
 *	Takes a void pointer, casts it to an unsigned long long and
 *	recursively calls ft_p_to_hex_fd to print address as hexidecimal to
 *	file descriptor.
 *	Returns nothing.
 */

int	ft_p_to_hex_buf(void *p, t_flags *seq_info)
{
	unsigned long long	nbl;
	char				c;

	nbl = (unsigned long long)p;
	if (nbl / 16 != 0)
	{
		if (ft_p_to_hex_buf((void *)(nbl / 16), seq_info))
			return (-1);
	}
	if (nbl % 16 > 9)
		c = ((nbl % 16) + 87);
	else
		c = ((nbl % 16) + '0');
	if (write_to_buf(seq_info, &c, 1, -1) <= 0)
		return (-1);
	return (0);
}

/*	*** ft_putunbr_fd (42 put unsigned number file descriptor) ***
 *
 *	Takes a number and prints as an unsigned integer to file descriptor.
 */

int	ft_putunbr_buf(unsigned int n, t_flags *seq_info)
{
	unsigned long	nbl;
	char			c;

	nbl = (unsigned long)n;
	if (nbl / 10 != 0)
	{
		if (ft_putunbr_buf(nbl / 10, seq_info))
			return (-1);
	}
	c = (nbl % 10 + '0');
	if (write_to_buf(seq_info, &c, 1, -1) <= 0)
		return (-1);
	return (0);
}
