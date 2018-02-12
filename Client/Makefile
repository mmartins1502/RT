#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 23:52:54 by nsampre           #+#    #+#              #
#    Updated: 2017/11/30 23:52:54 by nsampre          ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME			=	rt_client

SRC_BASE		=	$(shell find sources | grep '\.c' | cut -c 9- | sort)
SRC_BASE		+=	$(shell find ../common/primitives | grep '\.c' | sort | sed 's/^/..\//')
SRC_BASE		+=	$(shell find ../common/libvector | grep '\.c' | sort | sed 's/^/..\//')
SRC_BASE		+=	$(shell find ../common/mapping | grep '\.c' | sort | sed 's/^/..\//')

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror -O3

SRC_DIR			=	sources/
INC_DIR			=	includes/
OBJ_DIR			=	objs/

COMMON			=	../common/

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
MMD				=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.d))

LIBFT_DIR		=	../common/libft/
LIBFT_LIB		=	$(LIBFT_DIR)libft.a
LIBFT_INC		=	$(LIBFT_DIR)includes/

SDL2_F			=	-framework SDL2 -framework SDL2_ttf -framework SDL2_image -F ../common/frameworks/
SDL2_P			=	-rpath @executable_path/common/frameworks/
SDL2_I			=	-I ../common/frameworks/SDL2.framework/Headers
SDL2_TTF_I		=	-I ../common/frameworks/SDL2_ttf.framework/Headers
SDL2_IMG_I		=	-I ../common/frameworks/SDL2_image.framework/Headers

RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
YELLOW			=	"\033[1;33m"
BLUE			=	"\033[1;34m"
NC				=	"\033[0m"

all:
					@make -C $(LIBFT_DIR)
					@make -j $(NAME)
					@rm -rf common
					@echo "\n"$(GREEN)$(NAME) "compiled with success\n" $(NC)
					@mv $(NAME) ../ 

$(NAME):			$(OBJ_DIR) $(OBJS)
					@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INC_DIR) -I $(LIBFT_INC) -I $(COMMON) $(LIBFT_LIB) $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC) -I $(COMMON)
					@echo Compiling $(FLAGS) $(GREEN) $< $(NC)

clean:
					@printf "=> \x1B[31mDeleting $(NAME) .obj files...\x1B[37m\n"
					@rm -rf $(OBJS) $(MMD)
					@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
					@make -C $(LIBFT_DIR) clean

fclean:				clean
					@printf "=> \x1B[31mDeleting $(NAME)...\x1B[37m\n"
					@rm -f ../$(NAME)
					@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
					@make -C $(LIBFT_DIR) fclean

re:					fclean all

norme:
					@norminette $(INC_DIR)/*
					@norminette $(SRC_DIR)/*

.PHONY:				all clean fclean re norme
