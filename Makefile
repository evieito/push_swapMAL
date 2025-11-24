NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.c \
	  push_swap.c \
	  parse.c \
	  error.c \
	  stack.c \
		is_sorted.c \
		smal_sort.c \
	  radix_sort.c \
	best_move.c \
 	best_move_utils.c \
 	parse_utils.c \
	small_sort_utils.c \
	best_move_pick.c \
	best_move_config.c \
	radix_utils.c \
	radix_search.c \
	  operations_swap.c \
	  operations_push.c \
	  operations_rotate.c \
	  operations_rev_rotate.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
