##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

SRC		=	src/main.cpp \
			src/parser.cpp \
			src/Circuit.cpp \
			src/Component.cpp \
			src/Pin.cpp \
			src/Link.cpp \
			src/components/True.cpp \
			src/components/Output.cpp \

# TODO: Fix obj files
# OBJ		=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

FLAGS	=	-Wall -Wextra -Werror -I./includes

all:
	@g++ -o $(NAME) $(FLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)
