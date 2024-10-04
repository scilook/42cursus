CC = cc
CF = -Wall -Wextra -Werror
AR = ar
AF = rcs
INC = libft.h
OBJS = $(SRCS:.c=.o)
SRCS = $(wildcard *.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
SRCS_BONUS = $(wildcard *_bonus.c)
ALL_OBJS = $(OBJS) $(OBJS_BONUS)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AF) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CF) -c $< -o $@

bonus: $(ALL_OBJS)
	$(AR) $(AF) $(NAME) $(ALL_OBJS)

clean:
	rm -f $(ALL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus