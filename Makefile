##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

SRCBASIC	=	src/main.cpp \
				src/shell.cpp

SRC		=	src/utils.cpp \
			src/parser.cpp \
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
			src/components/Xor.cpp \
			src/components/Not.cpp \
			src/components/And4081.cpp \
			src/components/Or4071.cpp \
			src/components/Nand4011.cpp \
			src/components/Nor4001.cpp \
			src/components/Xor4030.cpp \

SRCTESTS = $(shell find tests -name "*.cpp")

# TODO: Fix obj files
# OBJ		=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

FLAGS	=	-Wall -Wextra -Werror -I./includes

all:
	@g++ -o $(NAME) $(FLAGS) $(SRC) $(SRCBASIC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	@g++ -o unit_tests $(SRC) $(SRCTESTS) $(FLAGS) -lcriterion
	@./unit_tests
