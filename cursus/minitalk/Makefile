NAME = server
CLIENT = client

SRC = ft_cases.c \
		ft_printf.c \
		ft_ultoa_base.c \
		minitalk_utils.c \
		check_input.c

OBJ = $(SRC:.c=.o)

SERVER_M = server.o

SERVER_M_BONUS = server_bonus.o

CLIENT_M = client.o

CLIENT_M_BONUS = client_bonus.o

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME) $(CLIENT)

$(NAME): $(OBJ) $(SERVER_M)
	$(CC) $(CFLAGS) $(OBJ) $(SERVER_M) -o $(NAME)

$(CLIENT): $(OBJ) $(CLIENT_M)
	$(CC) $(CFLAGS) $(OBJ) $(CLIENT_M) -o $(CLIENT) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(SERVER_M) $(CLIENT_M) $(SERVER_M_BONUS) $(CLIENT_M_BONUS)

fclean: clean
	rm -f $(NAME) $(CLIENT) 

re: fclean all

bonus: $(OBJ) $(SERVER_M_BONUS) $(CLIENT_M_BONUS)
	$(CC) $(CFLAGS) $(OBJ) $(SERVER_M_BONUS) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(CLIENT_M_BONUS) -o $(CLIENT)

.PHONY: bonus re clean fclean all
