/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:50:42 by skioridi          #+#    #+#             */
/*   Updated: 2024/09/18 18:48:39 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h> // directory stream

// defining all possible data types that we might have received
typedef enum s_type
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
} t_type;

// each token is a node in this struct
typedef struct s_token
{
	char		*content;
	t_type 		type; // type in enum
	int			i; // index
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;

typedef struct s_msh
{
	char		*line;
	int		exit;
	int		ret;
	t_token **lst_head;
	char **env;
}			t_msh;

typedef struct s_CMD
{
	char **s;
	int (*builtin_find)(t_msh *, struct s_CMD *);
	int redir_num;
	/*
	char *heredoc_file;
	t_token *redirection; ????
	*/
	
	struct s_CMD *next;
	struct s_CMD *prev;
} t_CMD;


// FUNCTION DECLARATIONS
// int     (*builtin_select(char *str))(t_msh *msh, t_CMD *command);

/* env_utils.c */
char **copy_matrix(char **src);

/* init.c */
void    signal_init(void);
t_msh    *init_msh(t_msh *msh);

/* free.c */
int		reset_msh(t_msh *msh);
void	ft_free_matrix(char **matrix);

// LEXER

t_type check_type(int c);
int handle_types(char *str, int i, t_token **lst_head);
int	quote_handler(char *str, int i, char c);
int add_node(t_token **lst_head, char *substring, t_type type);
int	skip_space(char *str, int i);
int 	split_words(char *str, int i, t_token **lst_head);
int	lexer(char *cmdline, t_token **lst_head);

/* lst_utils.c */
void	ft_tknclear(t_token **lst);
t_token	*newtoken(char *content, int type);
void	ft_tknadd_back(t_token **lst, t_token *newnode);

int    handleline(t_msh *msh);


#endif
