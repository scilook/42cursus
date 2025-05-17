CC = cc
CF = -Wall -Werror -Wextra
GET_NEXT_LINE_SRCS = get_next_line/get_next_line.c
SRCS = main.c seek_path.c pipex.c redirect.c
SRCS_BONUS = main_bonus.c seek_path_bonus.c pipex_bonus.c redirect_bonus.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBFT = libft/libft.a
NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CF) -I. $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(GET_NEXT_LINE_OBJS) $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CF) -I. $(GET_NEXT_LINE_OBJS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)
	touch bonus

$(LIBFT):
	make -C libft

%.o: %.c $(INC)
	$(CC) $(CF) -I. -c $< -o $@

clean:
	rm -f $(GET_NEXT_LINE_OBJS) $(OBJS) $(OBJS_BONUS) bonus
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
