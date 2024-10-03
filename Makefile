CC = cc
CF = -Wall -Wextra -Werror -std=c99
AR = ar
AF = rcs
INC = libft.h
OBJS = $(SRCS:.c=.o)
SRCS = $(wildcard *.c)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(AR) $(AF) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CF) -c $< -o $@ -include $(INC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re