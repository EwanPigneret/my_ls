SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)

NAME = my_ls

COMPILER = gcc
INCLUDE = -I ./include/
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

all : $(OBJ)
	$(COMPILER) $(OBJ) -o $(NAME) $(FLAGS)

re : fclean all

clean: remove
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.c.o:
	$(COMPILER) $(FLAGS) -c $< -o $@ $(INCLUDE)

remove :
	$(shell find  . -name '._*' -exec rm {} \;)