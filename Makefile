sourcefiles = check_sorted.c moves.c new_node.c push_swap.c sorting.c target.c targetb.c
objects = $(sourcefiles:.c=.o)
NAME = algo

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(objects)
	$(CC) -o $(NAME) $(objects)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -c $< -o $@
%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all
