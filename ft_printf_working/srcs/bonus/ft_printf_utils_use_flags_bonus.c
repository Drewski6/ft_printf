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

int	subseq_pound(t_flags *seq_info)
{
	if (seq_info->fs == 'x')
	{
		if (write_to_buf(seq_info, "0x", 2, 0) <= 0)
			return (-1);
	}
	else if (seq_info->fs == 'X')
	{
		if (write_to_buf(seq_info, "0X", 2, 0) <= 0)
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

int	subseq_build(t_flags *seq_info, va_list parg)
{
	int	padding;

	padding = 0;
	if (format_switch_buf(seq_info, parg))
		return (-1);
	if (seq_info->pound_flag == 1)
	{
		if (subseq_pound(seq_info))
			return (-1);
	}
	if (seq_info->width > 0)
	{
		padding = seq_info->width - seq_info->buf_len;
		while (padding > 0)
		{
			if (write_to_buf(seq_info, " ", 1, seq_info->minus_flag) <= 0)
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

int	subseq_print(t_flags *seq_info, int fd, int *print_count)
{
	write(fd, seq_info->buf, seq_info->buf_len);
	*print_count += seq_info->buf_len;
	return (0);
}

/*	*** write_to_buf (write to print buffer) ***
 *
 *	Rather than writing to a file descriptor, this write writes
 *	to a buffer.
 *	Basically str_join with len
 */

int	write_to_buf(t_flags *seq_info, char *str, size_t len, int wi)
{
	char	*new_buf;
	char	*new_buf_beg;
	char	*new_buf_end;
	char	*new_str;
	
	if (*str == 0)
	{
		*(seq_info->buf) = 0;
		seq_info->buf_len++;
		return (1);
	}
	new_str = ft_strdup(str);
	if (!new_str)
		return (-1);
	new_str[len] = 0;
	if (wi < 0)
		new_buf = ft_strjoin(seq_info->buf, new_str);
	else
	{
		new_buf_beg = ft_substr(seq_info->buf, 0, wi);
		if (!new_buf_beg)
			return (-1);
		new_buf_end = ft_strjoin(new_str, &(seq_info->buf[wi]));
		if (!new_buf_end)
			return (-1);
		new_buf = ft_strjoin(new_buf_beg, new_buf_end);
		free(new_buf_beg);
		free(new_buf_end);
	}
	if (new_buf == 0)
		return (-1);
	free(new_str);
	free(seq_info->buf);
	seq_info->buf = new_buf;
	seq_info->buf_len += len;
	return (len);
}
