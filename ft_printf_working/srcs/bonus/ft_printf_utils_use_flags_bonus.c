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

/*	*** subseq_build (subsequence build) ***
 *
 */

int	subseq_build(t_flags *seq_info, va_list parg)
{
	if (format_switch_buf_1(seq_info, parg))
		return (-1);
	if (seq_info->decimal_flag == 1)
	{
		if (subseq_decimal(seq_info) < 0)
			return (-1);
	}
	if (seq_info->pound_flag == 1)
	{
		if (subseq_pound(seq_info))
			return (-1);
	}
	if (seq_info->fs == 'd' || seq_info->fs == 'i')
	{
		if (subseq_sign(seq_info))
			return (-1);
	}
	if (seq_info->width > 0)
	{
		if (subseq_padding(seq_info))
			return (-1);
	}
	return (0);
}

/*	*** subseq_print (subsequence print) ***
 *
 */

int	subseq_print(t_flags *seq_info, int fd, int *print_count)
{
	write(fd, seq_info->buf, seq_info->buf_len);
	*print_count += seq_info->buf_len;
	return (0);
}

/*  *** ft_memjoin (42 memory join) ***
 *
 *
 */

char	*ft_memjoin(char const *s1, size_t s1_len, char const *s2,
	size_t s2_len)
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

/*	*** str_insert (string insert) ***
 *
 *
 */

char	*str_insert(t_flags *seq_info, char *new_str, size_t len, int wi)
{
	char	*new_buf;
	char	*new_buf_beg;
	char	*new_buf_end;

	if (wi < 0)
		new_buf = ft_memjoin(seq_info->buf, seq_info->buf_len, new_str, len);
	else
	{
		new_buf_beg = ft_substr(seq_info->buf, 0, wi);
		if (!new_buf_beg)
			return (0);
		new_buf_end = ft_memjoin(new_str, len, &(seq_info->buf[wi]),
				seq_info->buf_len - wi);
		if (!new_buf_end)
			return (0);
		new_buf = ft_memjoin(new_buf_beg, wi, new_buf_end,
				len + seq_info->buf_len - wi);
		free(new_buf_beg);
		free(new_buf_end);
	}
	if (new_buf == 0)
		return (0);
	return (new_buf);
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
	new_buf = str_insert(seq_info, new_str, len, wi);
	if (!new_buf)
		return (-1);
	free(new_str);
	free(seq_info->buf);
	seq_info->buf = new_buf;
	seq_info->buf_len += len;
	return (len);
}
