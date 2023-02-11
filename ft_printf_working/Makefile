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

# ***** Sources *****

SRCS = ft_printf.c \
    ft_printf_utils_1.c \
    ft_printf_utils_2.c

SRCS_DIR = srcs/mandatory/

BONUS_SRCS = ft_printf_bonus.c \
    ft_printf_utils_1_bonus.c \
    ft_printf_utils_2_bonus.c \
    ft_printf_utils_3_bonus.c \
    ft_printf_utils_t_flags_bonus.c \
	ft_printf_utils_use_flags_bonus.c \
	ft_printf_utils_subseq_helpers_bonus.c \
	ft_printf_utils_format_switch_bonus.c

BONUS_SRCS_DIR = srcs/bonus/

LIBFT_SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line_bonus.c \

# ***** Includes *****

INCS = ft_printf.h
BONUS_INCS = ft_printf_bonus.h
LIBFT_INCS = libft.h

INCS_DIR = includes/mandatory/
BONUS_INCS_DIR = includes/bonus/
LIBFT_INCS_DIR = libft/includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))
BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS))
LIBFT_OBJS = $(patsubst %.c,$(LIBFT_OBJS_DIR)%.o,$(LIBFT_SRCS))

OBJS_DIR = objs/mandatory/
BONUS_OBJS_DIR = objs/bonus/
LIBFT_OBJS_DIR = libft/objs/

# ***** Compiler and Archiver *****

CFLAGS = -Wall -Wextra -Werror

CC = cc

SLIB = ar rcs

# ***** Build *****

all: $(NAME)

$(NAME): $(OBJS)
	$(SLIB) $(NAME) -o $(OBJS)

bonus: $(BONUS_OBJS)
	@make -C libft --silent
	$(SLIB) $(NAME) -o $(BONUS_OBJS) $(LIBFT_OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	$(CC) $(CFLAGS) -c -I$(BONUS_INCS_DIR) $< -o $@

clean:
	@make -C libft clean --silent
	@rm -f $(OBJS) $(BONUS_OBJS) $(LIBFT_OBJS)

fclean:	clean
	@make -C libft fclean --silent
	@rm -f $(NAME)

re:	fclean all
