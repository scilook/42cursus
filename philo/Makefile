CC = cc
CF = -g -fsanitize=address #-Wall -Werror -Wextra
SRCS = philo.c 
OBJS = $(SRCS:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CF) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
