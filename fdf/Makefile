CC = cc
CF = -Wall -Werror -Wextra -L~/Documents/minilibx -lmlx -lXext -lX11
#LIBFT_SRCS = libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memset.c libft/ft_bzero.c libft/ft_atoi.c libft/ft_memmove.c libft/ft_memcpy.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_isprint.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_itoa.c libft/ft_lstlast_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstclear_bonus.c
SRCS = main.c
#LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = fdf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CF) -c $< -o $@

clean:
	rm -f 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re