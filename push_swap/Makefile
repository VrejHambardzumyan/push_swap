# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 16:36:30 by vhambard          #+#    #+#              #
#    Updated: 2025/04/23 17:31:58 by vhambard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

HEADER = push_swap.h

MANDATORY = push_swap.a

BONUS = 

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