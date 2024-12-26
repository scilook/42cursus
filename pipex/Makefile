CC = cc
CF = -Wall -Wextra -Werror
libft_SRCS = libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memset.c libft/ft_bzero.c libft/ft_atoi.c libft/ft_memmove.c libft/ft_memcpy.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_isprint.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_itoa.c libft/ft_lstlast_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstclear_bonus.c
SRCS = seek_path.c pipe.c redirect.c
SRCS_BONUS = seek_path.c pipe.c redirect.c
libft_OBJS = $(libft_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = pipex
BONUS = pipex

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(libft_OBJS) $(OBJS)
	$(CC) $(CF) -I. $(libft_OBJS) $(OBJS) -o $(NAME)

$(BONUS): $(libft_OBJS) $(OBJS_BONUS)
	$(CC) $(CF) -I. $(libft_OBJS) $(OBJS_BONUS) -o $(BONUS)

%.o: %.c $(INC)
	$(CC) $(CF) -I. -c $< -o $@

clean:
	rm -f $(libft_OBJS) $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
