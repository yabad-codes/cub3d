SRC = $(wildcard mandatory/*.c)
SRC_BNS = $(wildcard bonus/*.c)
MAP_PARSER = $(wildcard map_parser/*.c)
GNL = $(wildcard map_parser/get_next_line/*.c)

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BNS = $(addprefix $(OBJ_DIR)/, $(SRC_BNS:.c=.o))
OBJ_MAP_PARSER = $(addprefix $(OBJ_DIR)/, $(MAP_PARSER:.c=.o))
OBJ_GNL = $(addprefix $(OBJ_DIR)/, $(GNL:.c=.o))

NAME = cub3D
NAME_BNS = cub3D_bonus

CC = cc
CPPFLAGS = -Wall -Wextra -Werror

GLFW_LIB = $(shell brew --prefix glfw)
MLX = -lglfw -L"$(GLFW_LIB)/lib"
MLXLIB = MLX42/build/libmlx42.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(OBJ) $(OBJ_MAP_PARSER) $(OBJ_GNL) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(OBJ_MAP_PARSER) $(OBJ_GNL) $(MLXLIB)
	@$(CC) $^ $(MLX) $(LIBFT_LIB) -I. -o $@
	@echo "\033[1;32mPROJECT MANDATORY COMPILED SUCCESSFULLY\033[0m"

$(MLXLIB):  # Add a rule to build MLXLIB
	@mkdir -p MLX42/build
	@cd MLX42/build && cmake ..
	@$(MAKE) -C MLX42/build

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "\033[1;32mPROJECT CLEANED SUCCESSFULLY\033[0m"

fclean: clean
	@rm -f $(NAME) $(NAME_BNS)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "\033[1;32mPROJECT FCLEANED SUCCESSFULLY\033[0m"

re: fclean all

$(NAME_BNS): $(LIBFT_LIB) $(OBJ_BNS) $(OBJ_MAP_PARSER) $(OBJ_GNL) $(MLXLIB)
	@$(CC) $^ $(MLX) $(LIBFT_LIB) -I. -o $@
	@echo "\033[1;32mPROJECT BONUS COMPILED SUCCESSFULLY\033[0m"

bonus: $(NAME_BNS)

.PHONY: all bonus clean fclean re
