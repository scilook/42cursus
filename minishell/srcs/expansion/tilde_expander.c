/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:04:34 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:28 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "utils.h"
#include <stdlib.h>

static char	*_tilde_gethome(t_minishell *shell);
static void	_tilde_expand_single(char *new, char *home);
static void	_tilde_expand(const char *old, char *new, const char *home);

void	ft_tilde_expand(t_minishell *shell, char **str_ptr)
{
	char	*old;
	char	*home;
	char	*new;
	size_t	size;

	old = *str_ptr;
	home = _tilde_gethome(shell);
	size = ft_strlen(old);
	size += ft_strlen(home);
	new = ft_malloc(size + 2);
	new[0] = '\0';
	if (ft_strlen(old) == 1 && old[0] == '~')
		_tilde_expand_single(new, home);
	else if (ft_strncmp(old, "~/", 2) == 0)
		_tilde_expand(old, new, home);
	else
		ft_strcpy(new, old);
	new[size] = '\0';
	free(*str_ptr);
	*str_ptr = new;
}

static void	_tilde_expand_single(char *new, char *home)
{
	ft_strcpy(new, home);
}

static void	_tilde_expand(const char *old, char *new, const char *home)
{
	ft_strcat(new, home);
	ft_strcat(new, "/");
	ft_strcat(new, old + 2);
}

static char	*_tilde_gethome(t_minishell *shell)
{
	char	*env;

	env = minishell_getenv(shell, "HOME");
	if (env == NULL)
		return ("./");
	return (env);
}
