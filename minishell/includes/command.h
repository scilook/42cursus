/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:36:17 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:32:19 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "libft.h"

typedef struct s_runtime_info
{
	int					pid;
}						t_runtime_info;

typedef struct s_quote
{
	char				*start;
	char				*end;
	char				quote;
}						t_quote;

typedef enum e_r_instruction
{
	R_OUTPUT_REDIRECTION,
	R_APPENDING_TO,
	R_INPUT_REDIRECTION,
	R_HERE_DOC
}						t_r_instruction;

typedef struct s_redirectee
{
	int					dest;
	char				*filename;
}						t_redirectee;

typedef struct s_redirect
{
	struct s_redirect	*next;
	t_redirectee		redirector;
	t_redirectee		redirectee;
	t_r_instruction		instruction;
	char				*here_doc_eof;
}						t_redirect;

typedef struct s_command
{
	struct s_command	*next;
	struct s_command	*pipe;
	t_redirect			*redirects;
	char				**words;
	t_runtime_info		runtime;
}						t_command;

t_quote					*quote_init(char *start, char *end, char quote);
void					quote_list_add(t_list **list, t_quote *quote);
void					quote_destroy(void *quote);
void					print_each(void *ptr);
t_list					*find_quote(char *str);
t_list					*find_quotes(char *str);
t_quote					*is_in_quote(t_list *list, const char *ptr);

int						command_get_pipe_count(t_command *self);
t_command				*command_init(void);
void					command_destroy_all(t_command *self);

/* WORD */
void					word_add_to_last(char ***words, char *word);
void					word_destroy_all(char **words);

/* field splitter */

int						_wordlen(char *str, const char *charset,
							t_list *quotes);
char					*worddup(char *src, const char *charset,
							t_list *quotes);
int						_count_words(char *str, const char *charset,
							t_list *quotes);
char					**_split(char const *s, const char *charset,
							t_list *quotes);

#endif /* COMMAND_H */
