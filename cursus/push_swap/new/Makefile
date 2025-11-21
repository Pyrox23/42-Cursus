NAME = push_swap

SRC = main.c \
		check_input.c \
		push_swap_utils.c \
		ft_split.c \
		list_utils.c \
		sort_stack.c \
		operations.c \
		tiny_sort.c
		

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
