NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

HEADER = push_swap.h

MANDATORY = argv_handle.c error_free.c push_swap.c push.c reverse_rotate.c \
				rotate.c sort_stacks_initialisation.c sort_stacks.c\
				sort_three.c stack_initialisation.c stacks_utils.c\
				swap.c\

BONUS = //////////////////

OBJS = $(MANDATORY:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus