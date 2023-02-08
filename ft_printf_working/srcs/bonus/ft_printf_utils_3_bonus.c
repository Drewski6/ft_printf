/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:13:23 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/05 13:13:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** ft_iswsp (42 is whitespace or percent) ***
 *
 *	Determines if a character is a whitespace character (or %).
 */

int	ft_iswsp(const char *c)
{
	if (*c == 32 || *c == '\f' || *c == '\n'
		|| *c == '\r' || *c == '\t' || *c == '\v' || *c == '%')
		return (1);
	return (0);
}

/*	*** err_check (error checker) ***
 *
 *	Checks for initial conditions where the subsequence is not valid.
 *	First while loop gets seq_len by checking for whitespace, or NULL,
 *		increases len, then checks for format specifier. If one is found, break.
 *	Second while loop makes sure all characters are format specifiers, flags
 *		or digits for padding.
 *	Returns length of sequence 'seq_len' on success and -1 on error.
 */

int	err_check(const char *seq_start)
{
	int	seq_len;
	int	i;

	seq_len = 0;
	i = 0;
	while (!ft_iswsp(&seq_start[seq_len]) && seq_start[seq_len] != '\0')
	{
		seq_len++;
		if (ft_strchr("cspdiuxX%", seq_start[seq_len - 1]))
			break ;
	}
	while (i < seq_len)
	{
		if (ft_strchr("-0.# +cspdiuxX%", seq_start[i])
			|| ft_isdigit(seq_start[i]))
			i++;
		else
			return (-1);
	}
	if (seq_len == 0)
		return (-1);
	return (seq_len);
}

/*	*** subsequence_parser (subsequence parser) ***
 *
 *	Parses the subsequence (flags, precision, format specifiers) after a % sign.
 *	Returns -1 on error and 'seq_len' on success.
 */

int	subsequence_parser(const char *seq_start, va_list parg,
	int fd, int *print_count)
{
	int		seq_len;
	t_flags	*seq_info;
	int		ssb_ret;
	int		ssp_ret;
	char	*buf;

	seq_len = err_check(seq_start);
	if (seq_len < 0)
		return (-1);
	seq_info = t_flags_init();
	if (seq_info == 0)
		return (-1);
	if (t_flags_fill(seq_info, seq_start, seq_len))
		return (-1);
	buf = (char *)ft_calloc(10 * sizeof(char), 1);
	if (!buf)
		return (-1);
	ssb_ret = subseq_build(seq_info, parg, &buf);
	seq_info->buf = buf;
	//t_flags_inspect(seq_info);
	free(seq_info);
	if (ssb_ret == -1)
	{
		free(buf);
		return (-1);
	}
	ssp_ret = subseq_print(buf, fd, print_count);
	if (ssp_ret == -1)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	return (seq_len);
}
