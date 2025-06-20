NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

HEADER = libft.h

MANDATORY =  ft_atoi.c  ft_isdigit.c  ft_strlen.c  ft_strjoin.c ft_strlcpy.c\
 		ft_split.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \


OBJS = $(MANDATORY:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 