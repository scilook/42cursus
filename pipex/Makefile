CC = cc
CF = -Wall -Werror -Wextra -fsanitize=address
LIBFT_SRCS = libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memset.c libft/ft_bzero.c libft/ft_atoi.c libft/ft_memmove.c libft/ft_memcpy.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_isprint.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_itoa.c libft/ft_lstlast_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstclear_bonus.c
GET_NEXT_LINE_SRCS = get_next_line/get_next_line_bonus.c
SRCS = main.c seek_path.c pipex.c redirect.c
SRCS_BONUS = main_bonus.c seek_path_bonus.c pipex_bonus.c redirect_bonus.c
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = pipex

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(OBJS)
	$(CC) $(CF) -I. $(LIBFT_OBJS) $(OBJS) -o $(NAME)

bonus: $(LIBFT_OBJS) $(GET_NEXT_LINE_OBJS) $(OBJS_BONUS)
	$(CC) $(CF) -I. $(LIBFT_OBJS) $(GET_NEXT_LINE_OBJS) $(OBJS_BONUS) -o $(NAME)
	touch bonus

%.o: %.c $(INC)
	$(CC) $(CF) -I. -c $< -o $@

clean:
	rm -f $(LIBFT_OBJS) $(GET_NEXT_LINE_OBJS) $(OBJS) $(OBJS_BONUS) bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
