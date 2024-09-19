/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/19 12:13:02 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int     findtype(char *s)
{
    if (!strncmp(s, "echo", ft_strlen(s)) || !strncmp(s, "pwd", ft_strlen(s)) || !strncmp(s, "export", ft_strlen(s)) \
            || !strncmp(s, "cd", ft_strlen(s)) || !strncmp(s, "unset", ft_strlen(s)) || !strncmp(s, "env", ft_strlen(s)))
    {
        ft_printf("CMD = %s\n", s);
        return (CMD);
    }
    else if (!strncmp(s, "|", ft_strlen(s)))
        return (PIPE);
    else if (!strncmp(s, ">", ft_strlen(s)) || !strncmp(s, "<", ft_strlen(s)) || !strncmp(s, ">>", ft_strlen(s)) \
            || !strncmp(s, "<<", ft_strlen(s)))
        return (REDIR);
    return (0);
}

t_token *tokenize(char *str, int wdlen)
{
    t_token *a;

    char *substring = ft_substr(str, 0, wdlen);

    a = newtoken(substring);
    a->type = findtype(substring); // sort type
    return (a);
}

int add_node(t_token **lst_head, char *line, int i, int j)
{
    t_token *last;

    t_token *newnode = tokenize(&line[i], j);
    if (!*lst_head)
    {
        *lst_head = newnode;
        return (j);
    }
    last = ft_tknlast(*lst_head);
    last->next = newnode;
    newnode->prev = last;
    ft_tknadd_back(lst_head, newnode);
    return (j);
}

/* return value: nr of chars that later we'll copy
   example:
   cmdline = ola"adeus"ola
   we sent cmdline[4] as parameter, and the ft will stop at cmdline[10]
   ft_strchr will return 6 + 1, which is length of the word to tokenize*/
int strchr_wdlen(const char *s, int c)
{
	int		i;

	i = 1;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return (i + 1);
		i++;
	}
	return (0);
}

void split_cmds(char *line, int i, int j, t_token **lst_head)
{
    int flag = 0;
    int start = i;

    while (line[i] && i <= j)
    {
        if (line[i] == 39 && strchr_wdlen(&line[i], 39))
        {
            i += add_node(lst_head, line, i, strchr_wdlen(&line[i], 39));
            flag = 0;
        }
        else if (line[i] == 34 && strchr_wdlen(&line[i], 34))
        {
            if (!strchr_wdlen(&line[i], '$'))
                i += add_node(lst_head, line, i, strchr_wdlen(&line[i], 34));
            else
            {
                i += add_node(lst_head, line, i, strchr_wdlen(&line[i], 34));
                //add_node(lst_head, line, i, i + ft_strchr(&line[i + 1], "$"));
                //split_cmds(line, i + ft_strchr(&line[i + 1], "$"), j, lst_head);
            }
            flag = 0;
        }
        else if (line [i + 1] == '|' || line [i + 1] == '>' || line [i + 1] == '<')
        {
            if (line[i + 2] && line[i + 2] == line[i + 1])
            {
                add_node(lst_head, line, start, i);
                add_node(lst_head, line, i + 1, 2);
                i += 3;
                flag = 0;
            }
            else
            {
                add_node(lst_head, line, start, i);
                add_node(lst_head, line, i + 1, 1);
                i += 2;
                flag = 0;
            }
        }
        else
        {
            flag++;
            i++;
        }
    }
    if (flag == i)
        add_node(lst_head, line, start, i + 1);
        //add_node(lst_head, line, start, i);
    return ;
}

void new_lexer(char *cmdline, t_token **lst_head)
{
    int i = 0;
    int start;

    while (cmdline[i])
    {
        while (ft_isspace(cmdline[i] && cmdline[i])) //skip whitespace
            i++;
        start = i;
        while (!ft_isspace(cmdline[i]) && cmdline[i]) //skip word
            i++;
        split_cmds(cmdline, start, i - 1, lst_head);
    }
    return ;
}

