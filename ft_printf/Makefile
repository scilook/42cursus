CC = cc
CF = -Wall -Wextra -Werror
AR = ar
AF = rcs
INC = libft.h
SRCS = ft_printf.c vaprintf.c ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AF) $(NAME) $(OBJS)

%.o: %.c $(INC)
	$(CC) $(CF) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
