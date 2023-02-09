/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:32:59 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/30 18:33:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "../../libft/includes/libft.h"

typedef struct s_flags {
	char	minus_flag;			//	Set to 1 if minus flag is present.
	char	zero_flag;			//	Set to 1 if 0 flag is present.
	char	decimal_flag;		//	Set to 1 if decimal is present.
	char	pound_flag;			//	Set to 1 if # flag is present.
	char	space_flag;			//	Set to 1 if [ SPACE ] flag is present.
	char	plus_flag;			//	Set to 1 if + flag is present.
	char	fs;					//	Char that saves the format specifier.
	size_t	width;				//	Size of padding to add.
	size_t	precision;			//	Size of precision.
	size_t	buf_len;			//	Number of characters printed to buffer.
	char	*buf;				//	The string to be written to the fd.
}			t_flags;

int		ft_printf(const char *s, ...);
int		ft_putchar_buf(char c, t_flags *seq_info);
int		ft_putstr_buf(char *s, t_flags *seq_info);
int		ft_putnbr_buf(int n, t_flags *seq_info);
int		ft_dec_to_hex_lower_buf(unsigned int n, t_flags *seq_info);
int		ft_dec_to_hex_upper_buf(unsigned int n, t_flags *seq_info);
int		ft_p_to_hex_buf(void *p, t_flags *seq_info);
int		ft_putunbr_buf(unsigned int n, t_flags *seq_info);
int		ft_pointer_handle(t_flags *seq_info, va_list parg);
int		format_switch_buf(t_flags *seq_info, va_list parg);
int		err_check(const char *seq_start);
int		subsequence_parser(const char *seq_start, va_list parg, int fd, int *print_count);
int		ft_iswsp (const char *c);
t_flags	*t_flags_init(void);
void	t_flags_inspect(t_flags *seq);
int		t_flags_w_p(t_flags *seq_info, const char *seq_start, int seq_len);
int		t_flags_load_ints(char *seq_digits, size_t *seq_elem);
int 	t_flags_fill(t_flags *seq_info, const char *seq_start, int seq_len);
int		subseq_print(t_flags *seq_info, int fd, int *print_count);
int		write_to_buf(t_flags *seq_info, char *str, size_t len, int wi);
int		subseq_build(t_flags *seq_info, va_list parg);
char	*ft_memjoin(char const *s1, size_t s1_len, char const *s2, size_t s2_len);

#endif
