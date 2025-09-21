NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_FILES = minishell.c minishell_utils.c env/envp_utils.c env/envp_utils2.c \
 			parser/parser.c parser/parser_command.c parser/parser_redirect.c \
			lexer/lexer.c lexer/lexer_internal.c lexer/lexer_utils.c lexer/token.c \
			command/command_utils.c command/command.c command/redirect.c command/word.c command/quote.c command/quote_finder.c \
			expansion/tilde_expander.c expansion/expander.c expansion/parameter_expander.c expansion/field_splitter.c   expansion/field_splitter_utils.c expansion/quote_remover.c \
			utils/utils.c runner/runner.c runner/runner_utils.c runner/heredoc_handler.c \
			builtins/cd.c builtins/echo.c builtins/env.c builtins/export.c builtins/pwd.c builtins/builtin_utils.c builtins/unset.c \

INC_DIR = ./includes
SRC_DIR = srcs
OBJ_DIR = objs

LIBFT = Libft/libft.a

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(OBJ_DIR):
	mkdir -p $(sort $(addprefix $(OBJ_DIR)/, $(dir $(SRC_FILES))))

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I$(INC_DIR) -o $(NAME) -lreadline

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C Libft
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
