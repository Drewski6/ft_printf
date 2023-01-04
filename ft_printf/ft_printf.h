/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:32:59 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/30 18:33:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int ft_printf(const char *, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putpercent(void);
void	ft_dec_to_hex_lower(int n, int fd);
void	ft_dec_to_hex_upper(int n, int fd);
void	ft_p_to_hex(void *p, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);

#endif
