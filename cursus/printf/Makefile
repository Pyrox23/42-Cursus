NAME = libftprintf.a

SRC = ft_printf.c \
		ft_cases.c \
		ft_ultoa_base.c \
		ft_itoa.c \
		ft_strlen.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
