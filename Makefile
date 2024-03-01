##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

SRC		=	src/main.cpp \
			src/utils.cpp \
			src/parser.cpp \
			src/shell.cpp \
			src/gates.cpp \
			src/Circuit.cpp \
			src/Component.cpp \
			src/Factory.cpp \
			src/Pin.cpp \
			src/Link.cpp \
			src/components/True.cpp \
			src/components/False.cpp \
			src/components/Output.cpp \
			src/components/Input.cpp \
			src/components/Clock.cpp \
			src/components/And.cpp \
			src/components/Or.cpp \

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
