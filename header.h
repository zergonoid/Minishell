/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:50:42 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/30 14:02:09 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAXLINE 1024

typedef struct s_token
{
	char		*content;
	int 		type;
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;

typedef struct s_msh
{
	char		*line;
	int		exit;
	int		ret;
	t_token **lst_head;
}			t_msh;

// types for node struct
#define CMD 1
#define PIPE 2
#define REDIR 3
#define QUOTE 4
#define ENVVAR 5
//#define  6

void	ft_tknclear(t_token **lst);
t_token	*newtoken(char *content);
t_token	*ft_tknlast(t_token *lst);
void	ft_tknadd_back(t_token **lst, t_token *new);
int lexer(char *cmdline, t_token **lst_head);