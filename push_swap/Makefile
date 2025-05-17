CC = cc
CF = -Wall -Werror -Wextra
SRCS = push_swap.c queue_utils.c rank_queue.c swap_utils.c radix_sort2.c under6_sort.c
LIBFTPRINTF = ft_printf/libftprintf.a
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CF) $(OBJS) $(LIBFTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CF) -c $< -o $@

$(LIBFTPRINTF):
	make -C ft_printf

clean:
	rm -f $(OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
