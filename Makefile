SRC = main.c

OBJ = ${SRC:.c=.o}

NAME = cub3D

CC = cc

CPPFLAGS = -Wall -Wextra -Werror

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

MLX = $(FRAMEWORKS) -Iinclude -lglfw -L"/Users/yabad/goinfre/homebrew/opt/glfw/lib"

MLXLIB = MLX42/build/libmlx42.a

${NAME}: ${OBJ}
	${CC} ${OBJ} ${MLXLIB} ${CFLAGS} ${MLX} -o $@ && ./cub3D

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re