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

typedef struct s_flags {
	char	minus_flag;			//	Set to 1 if minus flag is present.
	char	zero_flag;			//	Set to 1 if 0 flag is present.
	char	decimal_flag;		//	Set to 1 if decimal is present.
	char	pound_flag;			//	Set to 1 if # flag is present.
	char	space_flag;			//	Set to 1 if [ SPACE ] flag is present.
	char	plus_flag;			//	Set to 1 if + flag is present.
	char	fs;					//	Char that saves the format specifier.
	size_t	padding;			//	Size of padding to add.
}			t_flags;

int		ft_printf(const char *s, ...);
void	ft_putchar_fd(char c, int fd, int *print_count);
void	ft_putstr_fd(char *s, int fd, int *print_count);
void	ft_putnbr_fd(int n, int fd, int *print_count);
void	ft_putpercent_fd(int fd, int *print_count);
void	ft_dec_to_hex_lower_fd(unsigned int n, int fd, int *print_count);
void	ft_dec_to_hex_upper_fd(unsigned int n, int fd, int *print_count);
void	ft_p_to_hex_fd(void *p, int fd, int *print_count);
void	ft_putunbr_fd(unsigned int n, int fd, int *print_count);

#endif
