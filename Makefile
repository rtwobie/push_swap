NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = main.c operations.c operation_manager.c input.c sort.c .tester.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
