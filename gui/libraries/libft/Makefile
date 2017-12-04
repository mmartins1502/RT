#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 20:40:13 by nsampre           #+#    #+#              #
#    Updated: 2017/07/01 08:42:18 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME		=	libft.a

SRC_BASE	=	array/ft_array_copy.c	\
				array/ft_array_len.c	\
				array/ft_free_array.c	\
				array/ft_post_realloc_array.c	\
				array/ft_pre_realloc_array.c	\
				array/ft_print_array.c	\
				char/ft_is_whitespace.c	\
				char/ft_isalnum.c	\
				char/ft_isalpha.c	\
				char/ft_isascii.c	\
				char/ft_isdigit.c	\
				char/ft_isprime.c	\
				char/ft_isprint.c	\
				char/ft_tolower.c	\
				char/ft_toupper.c	\
				convertion/ft_atod.c	\
				convertion/ft_atoi.c	\
				convertion/ft_atoll.c	\
				convertion/ft_itoa.c	\
				convertion/ft_xtoa.c	\
				convertion/ft_xtoi.c	\
				get_next_line/get_next_line.c	\
				lst/ft_lstadd.c	\
				lst/ft_lstdel.c	\
				lst/ft_lstdelone.c	\
				lst/ft_lstiter.c	\
				lst/ft_lstmap.c	\
				lst/ft_lstnew.c	\
				math/ft_factorial.c	\
				math/ft_pow.c	\
				mem/ft_bzero.c	\
				mem/ft_memalloc.c	\
				mem/ft_memccpy.c	\
				mem/ft_memchr.c	\
				mem/ft_memcmp.c	\
				mem/ft_memcpy.c	\
				mem/ft_memdel.c	\
				mem/ft_memmove.c	\
				mem/ft_memset.c	\
				printf/convers.c	\
				printf/ft_abs.c	\
				printf/ft_char_pf.c	\
				printf/ft_itoa_base.c	\
				printf/ft_itoa_pf.c	\
				printf/ft_printf.c	\
				printf/ft_putadr_pf.c	\
				printf/ft_putnchar.c	\
				printf/ft_putstr_lim.c	\
				printf/ft_putwchar.c	\
				printf/ft_str_pf.c	\
				printf/ft_strlen.c	\
				printf/parsing.c	\
				printf/print_d.c	\
				printf/print_x.c	\
				printf/read_spec.c	\
				printf/select.c	\
				printf/utils.c	\
				put/ft_putchar.c	\
				put/ft_putchar_fd.c	\
				put/ft_putendl.c	\
				put/ft_putendl_fd.c	\
				put/ft_putnbr.c	\
				put/ft_putnbr_fd.c	\
				put/ft_putstr.c	\
				put/ft_putstr_fd.c	\
				string/ft_cut_string.c	\
				string/ft_escape.c	\
				string/ft_is_quotestring.c	\
				string/ft_is_whitestring.c	\
				string/ft_post_realloc_str.c	\
				string/ft_str_fits_int.c	\
				string/ft_str_is_number.c	\
				string/ft_strcapitalize.c	\
				string/ft_strcat.c	\
				string/ft_strchr.c	\
				string/ft_strclr.c	\
				string/ft_strcmp.c	\
				string/ft_strcpy.c	\
				string/ft_strdel.c	\
				string/ft_strdup.c	\
				string/ft_strequ.c	\
				string/ft_striter.c	\
				string/ft_striteri.c	\
				string/ft_strjoin.c	\
				string/ft_strlcat.c	\
				string/ft_strlen.c	\
				string/ft_strlowcase.c	\
				string/ft_strmap.c	\
				string/ft_strmapi.c	\
				string/ft_strncat.c	\
				string/ft_strncmp.c	\
				string/ft_strncpy.c	\
				string/ft_strndup.c	\
				string/ft_strnequ.c	\
				string/ft_strnew.c	\
				string/ft_strnjoin.c	\
				string/ft_strnstr.c	\
				string/ft_strrchr.c	\
				string/ft_strreplace.c	\
				string/ft_strreplace_once.c	\
				string/ft_strsplit.c	\
				string/ft_strstr.c	\
				string/ft_strsub.c	\
				string/ft_strtrim.c	\
				string/ft_strupcase.c	\
				string/ft_trim_quotestr.c	\
				unix/ft_isdir.c	\

SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"
NC			=	"\033[0m"

all:
				@make -j $(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)
				@echo Compiling $(YELLOW) $< $(NC)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(dir $(OBJS))

clean:
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
