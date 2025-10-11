NAME = libftprintf.a

SRC1 = libft

SRC2 = printf

all: $(NAME)

$(NAME):
	+$(MAKE) -C $(SRC1)
	+$(MAKE) -C $(SRC2)
	ar rcsT $(NAME) $(SRC1)/libft.a $(SRC2)/printf.a

clean:
	+$(MAKE) -C $(SRC1) clean
	+$(MAKE) -C printf clean

fclean: clean
	+$(MAKE) -C $(SRC1) fclean
	+$(MAKE) -C printf fclean
	rm -f $(NAME)

re: fclean all

bonus:
	+$(MAKE) -C $(SRC1) bonus
	+$(MAKE) -C $(SRC2) bonus
	rm -f $(NAME)
	ar rcsT $(NAME) $(SRC1)/libft.a $(SRC2)/printf.a
