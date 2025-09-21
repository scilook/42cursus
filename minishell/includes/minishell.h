/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:29:09 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 20:21:55 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "command.h"
# include "token.h"
# include "utils.h"

typedef struct s_parser
{
	t_token			*cur;
	t_command		*commands;
	t_bool			err;
}					t_parser;

typedef struct s_envp_table
{
	char			*key;
	char			*value;
	int				flag;
}					t_envp_table;

typedef struct s_minishell
{
	t_envp_table	*envp_table;
	char			**envp;
	int				envp_size;
	int				pipe_in_fd;
	int				pipe_out_fd;

	int				stdin_fd;
	int				stdout_fd;

	t_parser		*parser;
	t_token			*tokens;

	int				last_exit_status;
}					t_minishell;

typedef enum e_var_flag
{
	ENV_FLAG = 0b00,
	EXPORT_FLAG = 0b01,
}					t_var_flag;

void				init_shell(t_minishell *shell, int argc, char **argv,
						char **envp);
void				destroy_shell(t_minishell *shell);
void				minishell_initenv(t_minishell *shell, char **envp);
char				*minishell_getenv(t_minishell *shell, char *key);
void				minishell_putenv(t_minishell *shell, char *env,
						t_var_flag flag);
char				**minishell_getpath(t_minishell *shell);
void				minishell_destroyenv(t_minishell *shell);
t_bool				dup2_and_close(int old, int new);
t_bool				dup_redirect(const t_command *cmd);
int					wait_command(t_command *cmd);
char				*find_filename_or_null(t_minishell *shell, char *cmd);
int					minishell_run(t_minishell *self, char *input);

void				heredoc_sig_handler(int signum);
void				sig_handler(int signum);

#endif /* MINISHELL_H */
