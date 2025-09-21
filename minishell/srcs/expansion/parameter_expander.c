/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:32:05 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 21:41:26 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "minishell.h"
#include "utils.h"

typedef struct s_parameter
{
	char		*start_p;
	char		*end_p;
	char		*variable_name;
	t_bool		brace;
}				t_parameter;

static void		_parameter_expand_recursive(t_minishell *shell, char **old_ptr,
					size_t index);
static void		_parameter_expand(t_minishell *shell, char **old_ptr,
					t_parameter parameter);
static t_bool	_should_expand(char *src, t_parameter param);
static void		_find_parameter(t_parameter *p, char *str);

void	parameter_expand(t_minishell *shell, char **str_ptr)
{
	_parameter_expand_recursive(shell, str_ptr, 0);
}

static t_bool	_should_expand(char *src, const t_parameter param)
{
	t_list	*lst;
	t_list	*cur;
	t_quote	*quote;

	lst = find_quotes(src);
	cur = lst;
	while (cur != NULL)
	{
		quote = ((t_quote *)(cur->content));
		if (quote->quote == '\\' && quote->end == param.start_p)
		{
			ft_lstclear(&lst, quote_destroy);
			return (FALSE);
		}
		if (quote->start < param.start_p && quote->end >= param.end_p
			&& quote->quote == '\'')
		{
			ft_lstclear(&lst, quote_destroy);
			return (FALSE);
		}
		cur = cur->next;
	}
	ft_lstclear(&lst, quote_destroy);
	return (TRUE);
}

static void	_parameter_expand_recursive(t_minishell *shell, char **old_ptr,
		const size_t index)
{
	t_parameter	parameter;
	char		*dollar;
	const char	*start = (*old_ptr) + index;

	dollar = ft_strchr(start, '$');
	if (dollar == NULL)
		return ;
	if (ft_strlen(start) <= 1)
		return ;
	parameter.variable_name = NULL;
	_find_parameter(&parameter, dollar);
	if (parameter.variable_name == NULL)
		return ;
	if (_should_expand(*old_ptr, parameter))
	{
		_parameter_expand(shell, old_ptr, parameter);
		_parameter_expand_recursive(shell, old_ptr, index);
		return ;
	}
	free(parameter.variable_name);
	_parameter_expand_recursive(shell, old_ptr, index + 1);
}

static void	_parameter_expand(t_minishell *shell, char **old_ptr,
		const t_parameter parameter)
{
	char	*env;
	char	*tmp;

	if (*parameter.variable_name == '?')
		env = ft_itoa(shell->last_exit_status);
	else
		env = minishell_getenv(shell, parameter.variable_name);
	if (env == NULL)
		env = "";
	tmp = ft_str_replace_range(*old_ptr, parameter.start_p, parameter.end_p,
			env);
	if (*parameter.variable_name == '?')
		free(env);
	free(parameter.variable_name);
	free(*old_ptr);
	*old_ptr = tmp;
}

static void	_find_parameter(t_parameter *p, char *str)
{
	char	*var_start_p;

	p->start_p = str++;
	p->brace = (*str == '{');
	if (*str != '?')
	{
		while (*str != '\0')
		{
			if ((p->brace && *str == '}') || (!p->brace
					&& !ft_is_varname(*str)))
				break ;
			++str;
		}
	}
	else
		++str;
	p->end_p = str;
	var_start_p = p->start_p + 1;
	if (p->brace)
	{
		var_start_p++;
		p->end_p++;
	}
	if (p->start_p != p->end_p)
		p->variable_name = ft_strndup(var_start_p, (str - var_start_p));
}
