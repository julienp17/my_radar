##
## EPITECH PROJECT, 2019
## my_radar
## File description:
## Project root Makefile
##

CC 			= 	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			= 	$(addprefix $(SRC_D), $(SRC_F))
OBJ 		= 	$(SRC:.c=.o)
SRC_D 		= 	src/
SRC_F 		=	usage.c \
				my_radar.c \
				draw.c \
				events.c \
				utils.c \
				booleans/boundary.c \
				booleans/pos.c \
				structures/plane.c \
				structures/tower.c \
				structures/window.c \
				structures/quadtree.c \
				structures/sim.c \
				structures/path.c \
				file_manipulation/get_file_buffer.c \
				file_manipulation/get_entities_from_file.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_boundary_overlaps.c \
				test_pos_match.c \
				test_pos_are_near.c \
				test_boundary_contains_pos.c \

INC			= 	-I./include/ -I./include/structures

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS) $(DBFLAGS)

DBFLAGS		=	-g -g3 -ggdb

LDFLAGS 	=	-L./lib -lmy -lcsfml-graphics -lcsfml-system -lm

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

NAME 		= 	my_radar

NAME_UT 	= 	unit_tests

all: $(NAME)

$(NAME):	makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS) $(DBFLAGS)

makelib:
	make -C ./lib/my/ all

tests_run: clean $(OBJ) $(OBJ_UT)
	echo -e "\e[1;32mCompiling $(NAME_UT) binary... \e[0m"
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)
	@rm -f $(SRC_UT_F:.c=.gcda)
	@rm -f $(SRC_UT_F:.c=.gcno)

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)
	make -C ./lib/my clean

re: fclean all