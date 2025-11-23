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
	  small_sort.c \
	  radix_sort.c \
	  operations_swap.c \
	  operations_push.c \
	  operations_rotate.c \
	  operations_rev_rotate.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
