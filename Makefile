# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:53:36 by evocatur          #+#    #+#              #
#    Updated: 2023/11/24 15:51:03 by evocatur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

SRC = $(MAIN_SRC)

MAIN_SRC = src/cub3d.c

OBJ = *.o

NONE="\033[0m"
GREEN="\033[32m"
GRAY="\033[2;37m"
CURSIVE="\033[3m"

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LINKS += -Lmlx_linux ./mlx_linux/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FLAGS_LINUX = -I/usr/include -Imlx_linux -O3
endif

ifeq ($(UNAME_S),Darwin)
LINKS += -lmlx -framework OpenGL -framework AppKit
endif

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm -rf $(OBJ)
	
$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS_LINUX) -c $(SRC) $(FLAGS)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

play0: all
	@./$(NAME) map/map_0.ber

error : all
	@./$(NAME) map/error_map.ber

big : all
	@./$(NAME) map/big.ber

extension : all
	@./$(NAME) map/big.bera

leaks: all
	@leaks --atExit -- ./$(NAME) map/map_0.ber

norm:
	@norminette $(SRC)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all