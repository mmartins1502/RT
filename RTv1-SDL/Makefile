#!/usr/bin/make -f

LIBPATH= libft

SDLPATH= SDL2-2.0.5

LIB= $(LIBPATH)/libft.a

SDL= $(SDLPATH)/lib/

NAME= Raytracer

CC= gcc

CFLAGS= -Wall -Wextra -Werror

LDFLAGS= -L libft -lft -I$(LIBPATH)/includes -L $(SDL) -lSDL2 -lSDL2main -I$(SDLPATH)/include

SRC_DIR = src/
SRC_BASE = $(shell find src | grep '\.c' | cut -c 5- | sort)
SRC = $(addprefix $(SRC_DIR), $(SRC_BASE))

OBJ= $(SRC:.c=.o)

all: $(LIB) $(SDL) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

$(SDL):
	cd SDL2-2.0.5; \
		./configure --prefix=$(shell pwd)/SDL2-2.0.5/ && make && make install

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)

sdl_clean:
		cd SDL2-2.0.5; \
		rm -Rf bin \
		rm -Rf lib \
		rm -Rf build \
		rm -f config.log

re: fclean all

norme:
					@norminette $(INC_DIR)/*
					@norminette $(SRC_DIR)/*

.PHONY:				all clean fclean re norme


# NAME			=	RTv1
# PUNCHLINE		=	simulate new universe

# SRC_BASE		=	$(shell find src | grep '\.c' | cut -c 5- | sort)

# CC				=	gcc

# FLAGS			= 	-O3
# FLAGS			+=	-Wall -Wextra -Werror

# SRC_DIR			=	src/
# INC_DIR			=	includes/
# OBJ_DIR			=	objs/

# SRCS			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
# OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

# LIBFT_DIR		=	libft/
# LIBFT_LIB		=	$(LIBFT_DIR)libft.a
# LIBFT_INC		=	$(LIBFT_DIR)includes/

# SDLPATH			=	SDL2-2.0.5
# SDL 			=	$(SDLPATH)/lib/

# # MLX				=	libmlx/libmlx.a -framework OpenGL -framework AppKit
# # MLX_INC			=	libmlx/

# all:
# 					@printf "\n["
# 					#@make -s -C $(MLX_INC)
# 					@make -s -C $(LIBFT_DIR)

# 					@make -s -j $(NAME)
# 					@printf "]\n"
# 					@printf "\n=> \x1B[32m$(NAME) ready to $(PUNCHLINE) ! ( ͡° ͜ʖ ͡°) \x1B[37m\n"

# $(NAME):			$(LIBFT_LIB) $(OBJ_DIR) $(OBJS) # $(MLX_INC)
# 					@$(CC) $(FLAGS) -L $(SDL) -lSDL2 -lSDLmain $(OBJS) -o $(NAME) -I $(INC_DIR) -I $(LIBFT_INC) -I $(SDLPATH)/include # $(LIBFT_LIB) $(MLX)

# $(LIBFT_LIB):
# 					make -C $(LIBFT_DIR)

# $(SDL):
# 					cd SDL2-2.0.5; \
# 						./configure --prefix=$(shell pwd)/SDL2-2.0.5/ && make && make install

# # $(MLX_INC):
# # 					make -C $(MLX_INC)

# $(OBJ_DIR):
# 					@mkdir -p $(OBJ_DIR)
# 					@mkdir -p $(dir $(OBJS))

# $(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIR) $(INC_DIR)
# 					@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC) # -I $(MLX_INC)
# 					@printf "\x1B[32m▒\e[0m"

# clean:
# 					@printf "=> \x1B[31mDeleting $(NAME) .obj files...\x1B[37m\n"
# 					@rm -rf $(OBJ_DIR)
# 					@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"
# 					@make -C $(LIBFT_DIR) clean

# fclean:				clean
# 					@printf "=> \x1B[31mDeleting $(NAME)...\x1B[37m\n"
# 					@rm -f $(NAME)
# 					@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"
# 					@make -C $(LIBFT_DIR) fclean
# 					cd SDL2-2.0.5; \
# 						rm -Rf bin \
# 						rm -Rf lib \
# 						rm -Rf build \
# 						rm -Rf config.log
# 					# @make -C $(MLX_INC) clean

# re:					fclean all