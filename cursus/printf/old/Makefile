NAME = libftprintf.a

SRCS = ft_atoi.o \
		ft_bzero.o \
		ft_calloc.o \
		ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_itoa.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_memset.o \
		ft_putchar_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_putstr_fd.o \
		ft_split.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlcpy.o \
		ft_strlen.o \
		ft_strmapi.o \
		ft_strncmp.o \
		ft_strnstr.o \
		ft_strrchr.o \
		ft_strtrim.o \
		ft_substr.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_printf.o \
		ft_cases.o \
		ft_ultoa_base.o

SRCS_BONUS = ft_lstadd_back_bonus.o \
			ft_lstadd_front_bonus.o \
			ft_lstclear_bonus.o \
			ft_lstdelone_bonus.o \
			ft_lstiter_bonus.o \
			ft_lstlast_bonus.o \
			ft_lstmap_bonus.o \
			ft_lstnew_bonus.o \
			ft_lstsize_bonus.o

OBJ = libft/libft.a \
		printf/printf.a

SRC1 = libft

SRC2 = printf

ifeq ($(BONUS),1)
	SRCS += $(SRCS_BONUS)
endif

all: $(NAME)

$(NAME): $(OBJ)
	+mkdir tmp
	cd tmp && ar x ../$(SRC1)/libft.a
	cd tmp && ar x ../$(SRC2)/printf.a
	cd tmp && ar rcs ../libftprintf.a $(SRCS)
	+rm -rf tmp

libft/libft.a:
	$(MAKE) -C $(SRC1)

printf/printf.a:
	$(MAKE) -C $(SRC2)

clean:
	$(MAKE) -C $(SRC1) clean
	$(MAKE) -C $(SRC2) clean

fclean:
	$(MAKE) -C $(SRC1) fclean
	$(MAKE) -C $(SRC2) fclean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) -C $(SRC1) bonus
	$(MAKE) -C $(SRC2) bonus
	$(MAKE) BONUS=1

.PHONY: bonus re fclean clean all