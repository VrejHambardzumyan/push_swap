NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
HEADER_DIR = includes

MANDATORY = src/argv_handle.c src/error_free.c src/push_swap.c src/push.c src/reverse_rotate.c \
			src/rotate.c src/sort_stacks_initialisation.c src/sort_stacks.c \
			src/sort_three.c src/stack_initialisation.c src/stack_utils.c src/swap.c

OBJS = $(MANDATORY:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIBFT_DIR) $(OBJS) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
