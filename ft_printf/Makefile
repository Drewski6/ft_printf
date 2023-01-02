# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 22:12:48 by dpentlan          #+#    #+#              #
#    Updated: 2022/12/29 22:12:50 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
    ft_printf_utils_1.c \
    ft_printf_utils_2.c

OBJS = ${SRCS:.c=.o}

INCS = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

SLIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(SLIB) $(NAME) -o $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
