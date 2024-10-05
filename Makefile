CC = cc
CF = -Wall -Wextra -Werror
AR = ar
AF = rcs
INC = libft.h
SRCS = $(filter-out %_bonus.c, $(wildcard *.c))
SRCS_BONUS = $(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
ALL_OBJS = $(OBJS) $(OBJS_BONUS)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AF) $(NAME) $(OBJS)

%.o: %.c $(INC)
	$(CC) $(CF) -I. -c $< -o $@

bonus: $(ALL_OBJS)
	$(AR) $(AF) $(NAME) $(ALL_OBJS)

clean:
	rm -f $(ALL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus