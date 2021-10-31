CC = gcc -g3 -fsanitize=address
FLAGS = -Wall -Wextra -Werror
SRC = pushswap.c
NAME = pushswap

all : $(NAME)

$(NAME) : $(SRC)
		$(CC) -o $(NAME) $(SRC)
clean:
	@echo "there is no object files"

fclean:clean
	@rm pushswap

re:fclean all