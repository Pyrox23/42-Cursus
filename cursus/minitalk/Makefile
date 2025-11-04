NAME = server
CLIENT = client

SRC = ft_cases.c \
		ft_printf.c \
		ft_ultoa_base.c \
		minitalk_utils.c \
		check_input.c

# SRC_BONUS = ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)

# OBJ_BONUS = $(SRC_BONUS:.c=.o)

SERVER_M = server.o

CLIENT_M = client.o

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
	rm -f $(OBJ) $(SERVER_M) $(CLIENT_M)

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

# bonus: $(OBJ_BONUS)
#	ar rcs $(NAME) $(OBJ_BONUS)
