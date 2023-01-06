/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:32:59 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/30 18:33:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_fd(char c, int fd, int *print_count);
void	ft_putstr_fd(char *s, int fd, int *print_count);
void	ft_putnbr_fd(int n, int fd, int *print_count);
void	ft_putpercent(int *print_count);
void	ft_dec_to_hex_lower(unsigned int n, int fd, int *print_count);
void	ft_dec_to_hex_upper(unsigned int n, int fd, int *print_count);
void	ft_p_to_hex(void *p, int fd, int *print_count);
void	ft_putunbr_fd(unsigned int n, int fd, int *print_count);

#endif
