NAME = fractol

MLX_DIR = mlx

MLX = $(MLX_DIR)/libmlx.a

SRC = main.c \
		fractals.c \
		fractol_utils.c \
		hook_functions.c \
		init_program.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $^ -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME) 

re: fclean all

.PHONY: bonus re clean fclean all
