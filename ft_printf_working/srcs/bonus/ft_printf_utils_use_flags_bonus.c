/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_use_flags_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:06:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/07 13:06:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** subseq_zero () ***
 *
 *
 */

/*
int	subseq_zero()
{

	return (0);
}
*/

/*	*** subseq_decimal () ***
 *
 *
 */

/*
int	subseq_decimal()
{

	return (0);
}
*/

/*	*** subseq_pound () ***
 *
 *
 */

int	subseq_pound(t_flags *seq_info, char **buf)
{
	if (seq_info->fs == 'x')
	{
		if (write_to_buf(buf, "0x", 2, 1) <= 0)
			return (-1);
	}
	else if (seq_info->fs == 'X')
	{
		if (write_to_buf(buf, "0X", 2, 1) <= 0)
			return (-1);
	}
	else if (seq_info->fs == 'd')
		return (0);
	else
		return (-1);
	return (0);
}

/*	*** subseq_space () ***
 *
 *
 */

/*
int	subseq_space()
{

	return (0);
}
*/

/*	*** subseq_plus () ***
 *
 *
 */

/*
int	subseq_plus()
{

	return (0);
}
*/

/*	*** subseq_build (make print) ***
 *
 *	Looks through the t_flags struct and starts printing subsequence.
 */

int	subseq_build(t_flags *seq_info, va_list parg, char **buf)
{
	int	buf_len;
	int	padding;

	buf_len = 0;
	padding = 0;
	if (format_switch_buf(seq_info->fs, parg, buf))
		return (-1);
	if (seq_info->pound_flag == 1)
	{
		if (subseq_pound(seq_info, buf))
			return (-1);
	}
	if (seq_info->width > 0)
	{
		buf_len = ft_strlen(*buf);
		padding = seq_info->width - buf_len;
		while (padding > 0)
		{
			if (write_to_buf(buf, " ", 1, !seq_info->minus_flag) <= 0)
				return (-1);
			padding--;
		}
	}
	return (0);
}

/*	*** subseq_print (subsequence print) ***
 *
 *	Prints out the buffer.
 */

int	subseq_print(char *buf, int fd, int *print_count)
{
	int len;

	len = ft_strlen(buf);
	write(fd, buf, len);
	*print_count += len;
	return (0);
}

/*	*** write_to_buf (write to print buffer) ***
 *
 *	Rather than writing to a file descriptor, this write writes
 *	to a buffer.
 *	Basically str_join with len
 */

int	write_to_buf(char **buf, char *str, size_t len, char inv_flag)
{
	char	*new_buf;
	char	*new_str;
	
	if (*str == 0)
		return (0);
	new_str = ft_strdup(str);
	if (!new_str)
		return (-1);
	new_str[len] = 0;
	if (inv_flag == 0)
		new_buf = ft_strjoin(*buf, new_str);
	else
		new_buf = ft_strjoin(new_str, *buf);
	if (new_buf == 0)
		return (-1);
	free(new_str);
	free(*buf);
	*buf = new_buf;
	return (ft_strlen(*buf));
}
