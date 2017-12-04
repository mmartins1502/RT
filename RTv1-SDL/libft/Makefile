#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 03:29:08 by nsampre           #+#    #+#              #
#    Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr        #
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
				convertion/ft_atoi.c	\
				convertion/ft_atoll.c	\
				convertion/ft_itoa.c	\
				convertion/ft_xtoa.c	\
				convertion/ft_xtoi.c	\
				convertion/ft_atod.c	\
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
				printf/binary_b.c	\
				printf/binary_char_hhb.c	\
				printf/binary_long_lb.c	\
				printf/binary_long_long_llb.c	\
				printf/binary_short_hb.c	\
				printf/char_c.c	\
				printf/char_s.c	\
				printf/count.c	\
				printf/fill.c	\
				printf/ft_fprintf.c	\
				printf/ft_printf.c	\
				printf/get_params.c	\
				printf/handle_arg.c	\
				printf/handle_arg_next.c	\
				printf/hex_char_hhx.c	\
				printf/hex_long_long_llx.c	\
				printf/hex_long_lx.c	\
				printf/hex_short_hx.c	\
				printf/hex_x.c	\
				printf/int_d_i.c	\
				printf/intmax_t_jd.c	\
				printf/is_params.c	\
				printf/long_ld.c	\
				printf/long_long_lld.c	\
				printf/no_format.c	\
				printf/octal_char_hho.c	\
				printf/octal_long_lo.c	\
				printf/octal_long_long_llo.c	\
				printf/octal_o.c	\
				printf/octal_short_ho.c	\
				printf/param_char.c	\
				printf/param_hex.c	\
				printf/param_int.c	\
				printf/param_octal.c	\
				printf/param_unsigned.c	\
				printf/percent.c	\
				printf/pointer_p.c	\
				printf/short_hd.c	\
				printf/signed_char_hhd.c	\
				printf/ssize_t_zd.c	\
				printf/uintmax_t_ju.c	\
				printf/unsigned_char_hhu.c	\
				printf/unsigned_int_u.c	\
				printf/unsigned_long_long_llu.c	\
				printf/unsigned_long_lu.c	\
				printf/unsigned_short_hu.c	\
				printf/wchar_t_lc.c	\
				printf/wchar_t_ls.c	\
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
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@make -j $(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)
				@printf "\e[38;5;208m▒\e[0m"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(dir $(OBJS))

clean:
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
