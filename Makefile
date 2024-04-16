

NAME    := push_swap
CFLAGS =  #-Wunreachable-code -Ofast
LIBFT := ./libft

HEADERS := -I./include -I /include -I$(LIBFT)
LIBS    := -ldl -pthread -lm $(LIBFT)/libft.a 
SRCS 	:= 	check_sorted.c moves.c new_node.c push_swap.c sorting.c target.c targetb.c
OBJS    := ${SRCS:.c=.o}

all:  libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft removemlx