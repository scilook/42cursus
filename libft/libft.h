/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:41:33 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/13 13:18:43 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

size_t	ft_strlen(const char *s)__attribute__((nonnull));
size_t	ft_strlcat(char *dst, const char *src, size_t size)
		__attribute__((nonnull));
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
		__attribute__((nonnull));
int		ft_strncmp(const char *s1, const char *s2, size_t n)
		__attribute__((nonnull));
char	*ft_strchr(const char *s, int c)__attribute__((nonnull));
char	*ft_strrchr(const char *s, int c)__attribute__((nonnull));
char	*ft_strnstr(const char *big, const char *little, size_t len)
		__attribute__((nonnull));

void	*ft_memchr(const void *s, int c, size_t n)__attribute__((nonnull));
void	*ft_memcpy(void *dest, const void *src, size_t n)
		__attribute__((nonnull));
void	*ft_memmove(void *dest, const void *src, size_t n)
		__attribute__((nonnull));
void	*ft_memset(void *s, int c, size_t n)__attribute__((nonnull));
void	ft_bzero(void *s, size_t n)__attribute__((nonnull));
int		ft_memcmp(const void *s1, const void *s2, size_t n)
		__attribute__((nonnull));

int		ft_atoi(const char *s)__attribute__((nonnull));
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s)__attribute__((nonnull));

char	*ft_substr(char const *s, unsigned int start, size_t len)
		__attribute__((nonnull));
char	*ft_strjoin(char const *s1, char const *s2)__attribute__((nonnull));
char	*ft_strtrim(char const *s1, char const *set)__attribute__((nonnull));
char	**ft_split(char const *s, char c)__attribute__((nonnull));
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
		__attribute__((nonnull));
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
		__attribute__((nonnull));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd)__attribute__((nonnull));
void	ft_putendl_fd(char *s, int fd)__attribute__((nonnull));
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
		__attribute__((nonnull));
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif /* LIBFT_H */