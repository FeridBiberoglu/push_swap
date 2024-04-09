sourcefiles =  check_sorted.c moves.c new_node.c push_swap.c sorting.c target.c

objects =		$(sourcefiles:.c=.o)

NAME =			algo

all:			$(NAME)

$(NAME):		$(objects)
	ar rcs algo $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(objects)

fclean:
	rm -f $(objects) $(NAME) a.out

re: 			fclean all