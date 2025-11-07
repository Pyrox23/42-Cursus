NAME = pipex

SRC = ft_cases.c \
		ft_printf.c \
		ft_ultoa_base.c \
		ft_split.c \
		pipex_utils.c \
		main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(CLIENT) 

re: fclean all

.PHONY: bonus re clean fclean all
