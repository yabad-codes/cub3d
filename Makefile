SRC = $(wildcard *.c)
MAP_PARSER = $(wildcard map_parser/*.c)
GNL = $(wildcard map_parser/get_next_line/*.c)

OBJ = ${SRC:.c=.o}
OBJ_MAP_PARSER = ${MAP_PARSER:.c=.o}
OBJ_GNL = ${GNL:.c=.o}

NAME = cub3D

CC = cc

CPPFLAGS = -Wall -Wextra -Werror 

GLFW_LIB = $(shell brew --prefix glfw)

MLX = -Iinclude -lglfw -L"$(GLFW_LIB)/lib"

MLXLIB = MLX42/build/libmlx42.a

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all:$(LIBFT_LIB) ${NAME}

${NAME}: ${OBJ} ${OBJ_MAP_PARSER} ${OBJ_GNL}
	${CC} $^ ${MLXLIB} ${CFLAGS} ${MLX} $(LIBFT_LIB) -I. -o $@


$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f ${OBJ} ${OBJ_GNL} ${OBJ_MAP_PARSER}
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f ${NAME}
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re