NAME = server
CLIENT = client

SRC = ft_cases.c \
		ft_printf.c \
		ft_ultoa_base.c \
		minitalk_utils.c

OBJ = $(SRC:.c=.o)

SERVER_M = server.o

CLIENT_M = client.o

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME) $(CLIENT)

bonus: $(NAME) $(CLIENT)

$(NAME): $(OBJ) $(SERVER_M)
	$(CC) $(CFLAGS) $(OBJ) $(SERVER_M) -o $(NAME)

$(CLIENT): $(OBJ) $(CLIENT_M)
	$(CC) $(CFLAGS) $(OBJ) $(CLIENT_M) -o $(CLIENT) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(SERVER_M) $(CLIENT_M)

fclean: clean
	rm -f $(NAME) $(CLIENT) 

re: fclean all

.PHONY: bonus re clean fclean all
