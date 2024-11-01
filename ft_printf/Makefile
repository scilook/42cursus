CC = cc
CF = -Wall -Wextra -Werror
AR = ar
AF = rcs
SRCS = ft_printf.c vaprintf.c ft_putchar_fd.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AF) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CF) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
