# **************************************************************************** #
#                                    SO_LONG                                   #
# **************************************************************************** #

NAME		= so_long

# Compiler
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRC_DIR		= src
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= mlx

# Sources
SRC			= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/parsing/parse_map.c \
			  $(SRC_DIR)/parsing/check_P_C_E.c \
			  $(SRC_DIR)/parsing/floodfill.c \
			  $(SRC_DIR)/parsing/error.c

OBJ			= $(SRC:.c=.o)

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

# OS Detection
UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# Includes
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Colors
GREEN		= \033[0;32m
RESET		= \033[0m

# Rules
all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
