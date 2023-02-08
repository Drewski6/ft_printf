/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:41:16 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:41:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*  *** ft_putchar_buf (42 put character to buffer) ***
 *
 *  Outputs the character 'c' to file descriptor.
 *  Returns nothing.
 */

int	ft_putchar_buf(char c, char **buf)
{
	char	*ch;

	ch = (char *)ft_calloc(2, sizeof(char));
	if (!ch)
		return (-1);
	ch[0] = c;
	if (write_to_buf(buf, ch, 1, 0) <= 0)
	{
		free(ch);
		return (-1);
	}
	free(ch);
	return (0);
}

/*  *** ft_putstr_buf (42 put string to buffer) ***
 *
 *  Outputs the string 's' to the given file descriptor.
 *  Returns nothing.
 */

int	ft_putstr_buf(char *s, char **buf)
{
	size_t	str_len;

	str_len = 0;
	if (s == 0)
	{
		if (write_to_buf(buf, "(null)", 6, 0) <= 0)
			return (-1);
		return (0);
	}
	str_len = ft_strlen(s);
	if (write_to_buf(buf, s, str_len, 0) <= 0)
		return (-1);
	return (0);
}

/*  *** ft_putnbr_fd_p (42 put number file descriptor) ***
 *
 *  Outputs the integer 'n' to the given file descriptor.
 *  Returns nothing.
 */

int	ft_putnbr_buf(int n, char **buf)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl < 0)
	{
		if (write_to_buf(buf, "-", 1, 0) <= 0)
			return (-1);
	}
	if (nbl / 10 != 0)
	{
		if (nbl < 0)
		{
			if (ft_putnbr_buf((nbl / 10) * -1, buf))
				return (-1);
		}
		else
		{
			if (ft_putnbr_buf(nbl / 10, buf))
				return (-1);
		}
	}
	if (nbl < 0)
		c = (((nbl % 10) * -1) + '0');
	else
		c = (nbl % 10 + '0');
	if (write_to_buf(buf, &c, 1, 0) <= 0)
		return (-1);
	return (0);
}
