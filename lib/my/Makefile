##
## EPITECH PROJECT, 2019
## my_radar
## File description:
## Libmy Makefile
##

CC 			= 	gcc

SRC			=	my_putchar.c    \
				my_putstr.c     \
				my_puterr.c     \
				my_count_char.c \
				my_strcmp.c     \
				my_intlen.c     \

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror

DBFLAGS		=	-g -g3 -ggdb

HEADER		=	my.h

NAME		=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
