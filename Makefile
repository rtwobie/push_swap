# config
NAME		:= push_swap
INC_DIR		:= inc
SRC_DIR		:= src
OBJ_DIR		:= obj
LIBFT_DIR	:= libft
CC			:= cc

# libs
LIBFT 		:= libft.a

# flags
CFLAGS		:=
CFLAGS		+= -O2
CFLAGS		+= -Wall
CFLAGS		+= -Werror
CFLAGS		+= -Wextra

CPPFLAGS	:=
CPPFLAGS	+= $(addprefix -I, $(INC_DIR))
CPPFLAGS	+= $(addprefix -I, $(LIBFT_DIR))

LDFLAGS		:=
LDFLAGS		+= -L$(LIBFT_DIR)

LDLIBS		:= -lft

ifeq ($(DEBUG), 1)
	CFLAGS	+= -ggdb3 -O0
	LDFLAGS	+= -ggdb3 -O0
endif

ifeq ($(ASAN), 1)
	CFLAGS	+= -fsanitize=address
	LDFLAGS	+= -fsanitize=address
endif

ifeq ($(LSAN), 1)
	CFLAGS	+= -fsanitize=leak
	LDFLAGS	+= -fsanitize=leak
endif

# sources
SRC			:=

vpath %.c src
SRC			+= main.c
SRC			+= input.c
SRC			+= input_utils.c
SRC			+= sort.c
SRC			+= sort_utils.c
SRC			+= operations.c
SRC			+= operation_manager.c
SRC			+= move.c
SRC			+= move_utils.c
SRC			+= instruction.c

# objects
OBJ 		:= $(SRC:.c=.o)
OBJ			:= $(addprefix $(OBJ_DIR)/,$(OBJ))

# rules
all: $(NAME)

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) $@
	$(RM) -f $(OBJ)
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) $@
	$(RM) -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) $(ARGS)

checker_linux:
	./$(NAME) $(ARGS) | ./checker_linux $(ARGS)

.PHONY: all clean fclean re
.PHONY: checker_linux
