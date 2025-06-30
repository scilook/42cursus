NAME = minishell
CC = cc
CFLAGS = -g2 -Wall -Werror -Wextra #-fsanitize=address

SRC_FILES = minishell.c token.c lexer.c parser.c
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

LIBFT = Libft/libft.a

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I$(INC_DIR) -o $(NAME) -lreadline

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -O3 -c $< -o $@

clean:
	$(MAKE) clean -C Libft
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
