CC = cc
CF = -Wall -Werror -Wextra
MLXOPTIONS = -Lminilibx-linux -lmlx -lXext -lX11
SRCS = main.c map_parse.c create_map.c image_utils.c key_event.c check_utils.c condition_check.c
LIBFTPRINTF = ft_printf/libftprintf.a
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CF) $(OBJS) $(LIBFTPRINTF) -o $(NAME) $(MLXOPTIONS)

%.o: %.c
	$(CC) $(CF) -c $< -o $@

$(LIBFTPRINTF):
	make -C ft_printf

mlx:
	make -C minilibx-linux

get_mlx:
	wget -O minilibx-linux.tgz "https://cdn.intra.42.fr/document/document/27071/minilibx-linux.tgz"
	tar -xvzf minilibx-linux.tgz
	rm minilibx-linux.tgz

clean:
	rm -f $(OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
