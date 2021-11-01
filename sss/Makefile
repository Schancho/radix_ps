CC  =	gcc -g3 -fsanitize=address
FLAGS   =   -Wall -Wextra -Werror
SRC =   pushswap.c
NAME    =   push_swap

all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	@rm push_swap

re: fclean all
