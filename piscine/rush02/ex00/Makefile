# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 17:16:54 by pablomar          #+#    #+#              #
#    Updated: 2025/06/29 18:28:00 by pablomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

MY_SOURCES = find.c \
			ft_append.c \
			ft_search_nb.c \
			ft_split.c \
			main.c \
			translate.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: RUSH

RUSH:$(MY_OBJECTS)
	cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

find.o:
	cc $(CFLAGS) -c find.c -o find.o

ft_append.o:
	cc $(CFLAGS) -c ft_append.c -o ft_append.o

ft_search_nb.o:
	cc $(CFLAGS) -c ft_search_nb.c -o ft_search_nb.o

ft_split.o:
	cc $(CFLAGS) -c ft_split.c -o ft_split.o

main.o:
	cc $(CFLAGS) -c main.c -o main.o

translate.o:
	cc $(CFLAGS) -c translate.c -o translate.o

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
