CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = build_it/ft_dup2.c build_it/ft_dup.c
OBJ = $(SRC:.c=.o)

NAME = lib/syscall.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.c: %.o
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
