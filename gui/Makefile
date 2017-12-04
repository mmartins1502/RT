# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 15:29:30 by itonoli-          #+#    #+#              #
#    Updated: 2017/11/29 03:29:55 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SELL COLORS
LRED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
LBLUE = \033[34;1m
PINK = \033[35m
LCYAN = \033[36m
END = \033[0m

# NAME
NAME = rt

#COMPILATION
CC= gcc -O3


# FLAGS= -Wall -Wextra -Werror

#FRAMEWORKS
SDL2_F		= -framework SDL2 -framework SDL2_ttf -framework SDL2_image -F ./frameworks/

SDL2_P		= -rpath @loader_path/frameworks/

SDL2_I		= -I ./frameworks/SDL2.framework/Headers

SDL2_TTF_I	= -I ./frameworks/SDL2_ttf.framework/Headers

SDL2_IMG_I	= -I ./frameworks/SDL2_image.framework/Headers

#LIB
LIBFT		= libraries/libft

DIR_S		= sources/

DIR_O		= obj/

HEADER		= includes/

SOURCES		= $(shell find sources | grep '\.c' | cut -c 9- | sort)

SRCS		= $(addprefix $(DIR_S), $(SOURCES))
OBJS		= $(addprefix $(DIR_O), $(SOURCES:.c=.o))

opti:
	@$(MAKE) all -j

all: obj $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft  -o $@ $^ $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)
	@ echo  "$(YELLOW)R$(END)$(LRED)T$(END):$(GREEN) Compilation done !$(END)"

obj:
	@mkdir -p $(DIR_O)
	@mkdir -p $(dir $(OBJS))

$(DIR_O)%.o: $(DIR_S)%.c
	@$(CC) -MMD $(FLAGS) -I $(HEADER) -c -o $@ $<
	@echo $<

norme:
	@make norme -C $(LIBFT)
	@echo
	norminette ./$(HEADER)
	@echo
	norminette ./$(DIR_S)

clean:
	@rm -f $(OBJS)
	 @make clean -C $(LIBFT)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)
	 @make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all -j

r: $(OBJS)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -o $(NAME) $^ $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

.PHONY: all, obj, norme, clean, fclean, re
