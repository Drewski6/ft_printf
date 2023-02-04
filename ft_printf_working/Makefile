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

# BONUS_NAME = libftprintf_bonus.a

# ***** Sources *****

SRCS = ft_printf.c \
    ft_printf_utils_1.c \
    ft_printf_utils_2.c

SRCS_DIR = srcs/

BONUS_SRCS = ft_printf_bonus.c \
    ft_printf_utils_1_bonus.c \
    ft_printf_utils_2_bonus.c

BONUS_SRCS_DIR = b_srcs/

# ***** Includes *****

INCS = ft_printf.h

INCS_DIR = includes/

BONUS_INCS = ft_printf_bonus.h

BONUS_INCS_DIR = b_includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = objs/

BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS))

BONUS_OBJS_DIR = b_objs/

# ***** Compiler and Archiver *****

CFLAGS = -Wall -Wextra -Werror

CC = cc

SLIB = ar rcs

# ***** Build *****

all: $(NAME)

$(NAME): $(OBJS)
	$(SLIB) $(NAME) -o $(OBJS)

bonus: $(BONUS_OBJS)
	$(SLIB) $(NAME) -o $(BONUS_OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(BONUS_INCS_DIR) $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
