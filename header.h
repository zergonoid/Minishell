/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:50:42 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/29 12:01:35 by marvin           ###   ########.fr       */
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

typedef struct s_msh
{
	char		*line;
	int		exit;
	int		ret;
}			t_msh;

// types for node struct
#define TYPE1 1
#define TYPE2 2
#define TYPE3 3
#define TYPE4 4
#define TYPE5 5

typedef struct s_token
{
	char		*content;
	int 		type;
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;


t_token	*newtoken(char *content);
t_token	*ft_tknlast(t_token *lst);
void	ft_tknadd_back(t_token **lst, t_token *new);
int lexer(char *cmdline);