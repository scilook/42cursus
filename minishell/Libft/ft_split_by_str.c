/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:41:08 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:23 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	_count_words(char *str, char *delim, int count);
static void	_solve(char *str, char *delim, char **result, int count);
static char	*_ndup(char *str, size_t n);

char	**ft_split_by_str(char *str, char *delim)
{
	int		count;
	char	**ret;

	count = _count_words(str, delim, 0);
	if (count == 0)
		return (NULL);
	count = count + 1;
	ret = ft_malloc(sizeof(char *) * (count + 1));
	ret[count] = NULL;
	_solve(str, delim, ret, 0);
	return (ret);
}

static void	_solve(char *str, char *delim, char **result, int count)
{
	char	*found;
	size_t	delim_len;
	size_t	remain;

	delim_len = ft_strlen(delim);
	found = ft_strnstr(str, delim, ft_strlen(str));
	if (found == NULL)
	{
		remain = ft_strlen(str);
		result[count] = _ndup(str, remain);
		return ;
	}
	result[count] = _ndup(str, found - str);
	_solve(found + delim_len, delim, result, count + 1);
}

static char	*_ndup(char *str, size_t n)
{
	char	*new;

	if (n == 0)
		return (ft_strdup(""));
	new = ft_malloc(n + 1);
	ft_strlcpy(new, str, n + 1);
	return (new);
}

static int	_count_words(char *str, char *delim, int count)
{
	char	*found;
	size_t	delim_len;

	delim_len = ft_strlen(delim);
	found = ft_strnstr(str, delim, ft_strlen(str));
	if (found == NULL)
		return (count);
	return (_count_words(found + delim_len, delim, count + 1));
}
