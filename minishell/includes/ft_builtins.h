/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:03:27 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:24:54 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

# include "minishell.h"
# include "utils.h"

typedef enum e_builtin
{
	NONE,
	EXIT,
	CD,
	EXPORT,
	UNSET,
	ENV,
	PWD,
	ECHO
}			t_builtin;

int			ft_echo(char **argv);
int			ft_cd(t_minishell *shell, char **argv);
int			ft_pwd(void);
int			ft_export(t_minishell *shell, char **argv);
int			ft_unset(t_minishell *shell, char **argv);
int			ft_env(t_minishell *shell);
t_builtin	is_builtin_command(t_command *cmd);
int			_builtin_exec(t_command *cmd, t_minishell *shell, t_builtin builtin,
				t_bool is_child);

#endif /* FT_BUILTINS_H */
