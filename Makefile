# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:53:36 by evocatur          #+#    #+#              #
#    Updated: 2023/11/24 20:21:17 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

SRC = $(UTILS) $(WINDOW) $(KEY) $(GAME_LOGIC) $(LIBFT_SRC) $(MAP_READ) $(GAME_ENGINE) $(MAIN_SRC)

MAIN_SRC = src/cub3d.c

UTILS = src/utils/exit.c src/utils/string_utils.c  src/utils/utils.c

WINDOW = src/window/window.c

KEY = src/key/key.c

GAME_LOGIC = src/game_logic/main_loop.c

GAME_ENGINE = src/game_engine/renderer.c

MAP_READ = src/map_read/map_read.c src/map_read/init_map.c

LIBFT_SRC = lib/ft_libft/ft_isdigit.c lib/ft_libft/ft_memset.c lib/ft_libft/ft_split.c lib/ft_libft/ft_strtrim.c lib/ft_libft/ft_isprint.c\
lib/ft_libft/ft_putchar_fd.c lib/ft_libft/ft_strlcat.c lib/ft_libft/ft_substr.c lib/ft_libft/ft_atoi.c lib/ft_libft/ft_itoa.c lib/ft_libft/ft_putendl_fd.c \
lib/ft_libft/ft_strlcpy.c lib/ft_libft/ft_tolower.c lib/ft_libft/ft_bzero.c lib/ft_libft/ft_putnbr_fd.c lib/ft_libft/ft_strlen.c \
lib/ft_libft/ft_toupper.c lib/ft_libft/ft_calloc.c lib/ft_libft/ft_memchr.c lib/ft_libft/ft_putstr_fd.c lib/ft_libft/ft_strmapi.c lib/ft_libft/ft_isalnum.c \
lib/ft_libft/ft_memcmp.c lib/ft_libft/ft_strncmp.c lib/ft_libft/ft_isalpha.c lib/ft_libft/ft_memcpy.c\
lib/ft_libft/ft_strnstr.c lib/ft_libft/ft_isascii.c lib/ft_libft/ft_memmove.c lib/ft_libft/ft_strdup.c lib/ft_libft/ft_strrchr.c lib/ft_libft/ft_striteri.c \
lib/ft_libft/ft_printf.c lib/ft_libft/ft_printf_utilis.c lib/ft_libft/ft_printf_flag.c lib/ft_libft/ft_printf_hex.c lib/ft_libft/ft_printf_p.c \
lib/ft_libft/ft_printf_unsigned.c lib/ft_libft/ft_lstadd_back.c lib/ft_libft/ft_lstadd_front.c lib/ft_libft/ft_lstclear.c lib/ft_libft/ft_lstdelone.c \
lib/ft_libft/ft_lstiter.c lib/ft_libft/ft_lstlast.c lib/ft_libft/ft_lstmap.c lib/ft_libft/ft_lstnew.c lib/ft_libft/ft_lstsize.c \
lib/ft_libft/get_next_line.c lib/ft_libft/get_next_line_utils.c

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

FLAGS = -lm

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

play: all
	@./$(NAME) map/test.cub

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