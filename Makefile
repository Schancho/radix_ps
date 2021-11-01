CC  =	gcc -g3 -fsanitize=address
FLAGS   =   -Wall -Wextra -Werror
SRC =   pushswap.c operations.c utils1.c utils2.c utils3.c sort.c
NAME    =   push_swap

all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	@rm push_swap

re: fclean all
