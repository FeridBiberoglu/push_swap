NAME		=	push_swap
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g
HEADER		=	push_swap.h
LIBFTDIR	= 	./libft

SRCS 		= 	check_sorted.c moves.c new_node.c push_swap.c sorting.c target.c targetb.c

LIBFT		= 	$(LIBFTDIR)/libft.a
OBJS		=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR) all

all:	$(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFTDIR)

fclean: clean
	@rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re