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
	if (!ft_memcmp(seq_info->buf, "0", 2))
		return (0);
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
			if (seq_info->zero_flag == 0)
			{
				if (write_to_buf(seq_info, " ", 1, seq_info->minus_flag) <= 0)
					return (-1);
			}
			else
			{
				if (*(seq_info->buf) == '-')
				{
					if (write_to_buf(seq_info, "0", 1, seq_info->minus_flag + 1) <= 0)
						return (-1);
				}
				else
				{
					if (write_to_buf(seq_info, "0", 1, seq_info->minus_flag) <= 0)
						return (-1);
				}
			}
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

/*  *** ft_strjoin (42 string join) ***
 *
 *  Takes two strings 's1' and 's2'.
 *  Returns a newly allocated memory space containing copies of 's1' memory
 *  space followed by 's2' memory space.
 */

char	*ft_memjoin(char const *s1, size_t s1_len, char const *s2, size_t s2_len)
{
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (s1_len + s2_len + 1));
	ft_memcpy(ptr, (char *)s1, s1_len);
	ft_memcpy((ptr + s1_len), (char *)s2, s2_len);
	return (ptr);
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
	
	if (*str == 0 && len == 1)
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
		new_buf = ft_memjoin(seq_info->buf, seq_info->buf_len, new_str, len);
	else
	{
		new_buf_beg = ft_substr(seq_info->buf, 0, wi);
		if (!new_buf_beg)
			return (-1);
		new_buf_end = ft_memjoin(new_str, len, &(seq_info->buf[wi]), seq_info->buf_len - wi);
		if (!new_buf_end)
			return (-1);
		new_buf = ft_memjoin(new_buf_beg, wi, new_buf_end, len + seq_info->buf_len - wi);
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
