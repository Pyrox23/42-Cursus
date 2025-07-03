NAME = bsq

MY_SOURCES = check_map.c \
			map_utils.c \
			solve.c \
			ft_split.c \
			main.c \
			input.c \
			ft_append.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: BSQ

BSQ:$(MY_OBJECTS)
	cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
