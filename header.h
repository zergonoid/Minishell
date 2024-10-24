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

// Global struct, in order to handle more general feelings/problems
// What exactly is the point of this/implementation?
typedef struct s_state
{
	int		errno;
	int		in_cmd;
	int		in_heredoc;
	int		stop_heredoc;

}	t_state; // CANNOT HAVE IT - find another way
 // u can have global state integer - Create an enum for the 4 variables
 // global is an integer - compare the integer to the enum values.
 
extern t_state	g_state;

// TYPE: Selection of type (|, >, >>, <, <<) for non-text token
typedef enum s_type
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
} t_type;

// MSH: Master struct, tools for the whole program.
typedef struct s_msh
{
	char		*line; 		// the line we've received in beginning
	char		**paths;	// useful, from pipex, from what I remember. It's what madalena did 4 it
	char		**envp;		// our copied version that we can alter

	int			exit;		// my own invention, to exit the loop, but maybe we've resolved it

	struct s_command_table *cmd_tbl; // link to the command tables
	struct s_token 	*lst_head;

	char		*pwd;		// store the pwd
	char		*old_pwd;	// store the previous pwd

	int			*pid; 		// child processes?
	int 		pipes; 		// general number of pipes in program?

	int			ret;
	bool		heredoc; 	// This is for if we are inside a heredoc
	bool		reset; 		// This is for if the struct has been reset (?)

}			t_msh;

// TOKENS : [lexer] - unformulated, unorganized, all tokens received
// Delimiter for construction: 	SPACES (except when inside quotemarks)
typedef struct s_token
{
	char		*content;	// either string content here (if word/command/string)
	t_type 		type;		// or type in case of redir/pipe [as enum]
	int			i;			// index of token
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;


/* PARSER : [parser] - Organizes the info from TOKENS into the COMMAND TABLES*/
typedef struct s_parser
{
	t_token *lst_head;		// link to all tokens of lexer
	t_token	*redirections;	// How does this work
	int		redir_number;	// how many redirections

	struct s_msh *msh;		// link to the master struct 

}	t_parser;


// COMMAND TABLES : [parser] - Organized, structured versions of commands
// Includes redirections, infiles and outfiles, and other possibilities
// Delimiter for construction: PIPES
typedef struct s_command_table
{
	char	**arguments;
	int		(*builtin_select)(t_msh *, struct s_command_table *);
	
	char	*heredoc_file;
	t_token *redirections; // How does this one work? How is redirection a token
	int		redir_number;
	
	struct s_command_table *next;
	struct s_command_table *prev;
} t_command_table;


// FUNCTION DECLARATIONS
// int     (*builtin_select(char *str))(t_msh *msh, t_cmd *command);

// BUILTINS
int     (*builtin_select(char *str))(t_msh *msh, t_command_table *table);
int 	builtin_cd(t_msh *msh, t_command_table *command);
int 	builtin_echo(t_msh *msh, t_command_table *cmd);
int 	builtin_export(t_msh *msh, t_command_table *cmd);
int 	builtin_unset(t_msh *msh, t_command_table *cmd);
int 	builtin_pwd(t_msh *msh, t_command_table *cmd);
int		builtin_env(t_msh *msh, t_command_table *cmd);
int		builtin_exit(t_msh *msh, t_command_table *cmd);

// LEXER
// handlers.c
t_type	check_type(int c);
int 	handle_types(char *str, int i, t_token **lst_head);
int		quote_handler(char *str, int i, char c);
// lexer.c
int 	add_node(t_token **lst_head, char *substring, t_type type);
int		skip_space(char *str, int i);
int		split_words(char *str, int i, t_token **lst_head);
int		lexer(char *cmdline, t_token **lst_head);

// UTILS
// envp_utils.c
int     parse_envp(t_msh *msh);
// gen_utils.c
char	**copy_matrix(char **src);
int		quote_verify(char *str);
int		get_pwd(t_msh *msh);
// lst_utils.c
void	token_clear(t_token **lst);
t_token	*token_new(char *content, int type);
void	token_addback(t_token **lst, t_token *newnode);
void	token_delone(t_token **token, int index);
// parser_utils.c
int		count_arguments(t_token *lst_head);
void	count_pipes(t_token *lst_head, t_msh *msh);
// tbl_utils.c
t_command_table *table_new(char **args, int redir_no, t_token *redirections);
void    table_addback(t_command_table **tbl_head, t_command_table *new);
void    table_clear(t_command_table **tbl_head);

// init.c
int     init_msh(t_msh *msh);
int     prep(t_msh *msh);

// error.c
int ft_error(int errno, t_msh *msh);

// reset_msh.c
void    clear_command_tables(t_command_table **lst);
int		reset_msh(t_msh *msh);
void	ft_free_matrix(char **matrix);

// signals.c
void    q_handler(int sig);
void	signal_init(void);

// parser.c
int parser(t_msh *msh);

// main.c
int    handleline(t_msh *msh);

#endif
