##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	my_runner

SRC		=	src/principal_functions/main.c 				\
			src/principal_functions/my_runner.c			\
			src/support_functions/init_game_var.c 		\
			src/support_functions/init_images.c 		\
			src/principal_functions/game_setup.c 		\
			src/principal_functions/read_file.c 		\
			src/principal_functions/move_sprites.c 		\
			src/support_functions/my_int_to_str.c 		\

OBJ	=	$(SRC:.c=.o)

CFLAGS		+=	-I./include/ -l csfml-graphics -l csfml-system -l csfml-audio -g3

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS)

make_lib:
		$(MAKE) -C lib/my

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

run_tests:

re:		fclean all
		$(MAKE) re -C lib/my
