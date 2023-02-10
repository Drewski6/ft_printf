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

LIBFT_SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

LIBFT_SRCS_DIR = libft/srcs/mandatory/

# ***** Includes *****

INCS = ft_printf.h

INCS_DIR = includes/mandatory/

BONUS_INCS = ft_printf_bonus.h

BONUS_INCS_DIR = includes/bonus/

LIBFT_INCS = libft.h

LIBFT_INCS_DIR = libft/includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS))

LIBFT_OBJS = $(patsubst %.c,$(LIBFT_OBJS_DIR)%.o,$(LIBFT_SRCS))

OBJS_DIR = objs/
BONUS_OBJS_DIR = objs/
LIBFT_OBJS_DIR = objs/

# removed these, because when uploading to git repo, these folders were not included and it caused issues.
#OBJS_DIR = objs/mandatory/
#BONUS_OBJS_DIR = objs/bonus/
#LIBFT_OBJS_DIR = libft/objs/mandatory/

# ***** Compiler and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

SLIB = ar rcs

# ***** Build *****

all: $(NAME)

$(NAME): $(OBJS)
	$(SLIB) $(NAME) -o $(OBJS)

bonus: $(BONUS_OBJS) $(LIBFT_OBJS)
	$(SLIB) $(NAME) -o $(BONUS_OBJS) $(LIBFT_OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(BONUS_INCS_DIR) $< -o $@

$(LIBFT_OBJS_DIR)%.o: $(LIBFT_SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(LIBFT_INCS_DIR) $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJS) $(BONUS_OBJS) $(LIBFT_OBJS)

fclean:	clean
	@make fclean -C libft
	@rm -f $(NAME)

re:	fclean all
