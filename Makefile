# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 15:41:06 by evieito-          #+#    #+#              #
#    Updated: 2025/11/23 18:36:42 by evieito-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.c \
	  push_swap.c \
	  parse_utils.c \
	  parse.c \
	  error.c \
	  stack.c \
	  is_sorted.c \
	  small_sort.c \
	radix_sort.c \
	chunk_sort.c \
  	chunk_utils1.c \
  	chunk_utils2.c \
  	chunk_utils3.c \
  	chunk_reinsert.c \
	  operations_swap.c \
	  operations_push.c \
	  operations_rotate.c \
	  operations_rev_rotate.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
