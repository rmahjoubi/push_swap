NAME = checker

$(NAME):
		gcc -ggdb3 ./srcs/checker.c libft/srcs/*.c libft/printf/srcs/*.c -I ./incs -I libft/includes -I libft/printf/includes -o $(NAME)

all: $(NAME)

clean:
	rm checker

re: clean all
