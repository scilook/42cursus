/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:51 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/23 13:58:26 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKEN_H
# define MINISHELL_TOKEN_H
# include "minishell.h"


typedef enum {
	TOKEN_TOKEN,
    TOKEN_WORD,
    TOKEN_ASSIGNMENT_WORD,
    TOKEN_NAME,
    TOKEN_NEWLINE,
    TOKEN_IO_NUMBER,
    TOKEN_AND_IF,
    TOKEN_OR_IF,
    TOKEN_DSEMI,
    TOKEN_DLESS,
    TOKEN_DGREAT,
    TOKEN_LESSAND,
    TOKEN_GREATAND,
    TOKEN_LESSGREAT,
    TOKEN_DLESSDASH,
    TOKEN_CLOBBER,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_BANG,
    TOKEN_LESS,
    TOKEN_GREAT,
} t_token_type;

typedef struct s_token {
    t_token_type type;
    char* lexeme_or_null;
    struct s_token* next_or_null;
} t_token;

t_token* token(t_token_type type, char* lexeme_or_null, t_token* next_or_null);
void add_token_to_last(t_token** head_ptr, t_token* to_add);
void destroy(t_token* token);
void destroy_all(t_token* token);


#endif /* MINISHELL_TOKEN_H */