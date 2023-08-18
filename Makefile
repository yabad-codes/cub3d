SRC = 	main.c \
		map.c \
		math.c \
		player.c \
		key_handler.c \
		free.c \

OBJ = ${SRC:.c=.o}

NAME = cub3D

CC = cc -fsanitize=address -g

CPPFLAGS = -Wall -Wextra -Werror

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

MLX = $(FRAMEWORKS) -Iinclude -lglfw -L"/Users/yabad/goinfre/homebrew/opt/glfw/lib"

MLXLIB = MLX42/build/libmlx42.a

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all:$(LIBFT_LIB) ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} ${MLXLIB} ${CFLAGS} ${MLX} $(LIBFT_LIB) -o $@ && ./cub3D


$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f ${OBJ}
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f ${NAME}
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re