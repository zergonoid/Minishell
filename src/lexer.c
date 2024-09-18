/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/18 19:12:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	makeword(const char *s)
{
    int i = 0;
    int len = 0;


    while (s[i] && !ft_isspace(s[i]))
    {
        if ((s[i] == '"' && strchr(&s[i + 1], '"')) || (s[i] == 39 && strchr(&s[i + 1], 39)))
        {
            i++;
            while (s[i] != 39 && s[i] != '"')
            {
                i++;
                len++;
                ft_printf("is here\n");
            }
            len++;
        }
        else
        {
            len++;
            i++;
        }
    }
    return (len);
}

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
    //else if (s[0] == '"' && s[ft_strlen(s)] == '"')
    //else

    // ft_putstr_fd(char *string_that_failed, int 2);
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

int lexer(char *cmdline, t_token **lst_head)
{
    int i = 0;
    int wdlen = 0;
    t_token *newnode;
    newnode = NULL;

    while (cmdline[i])
    {
        while (ft_isspace(cmdline[i]) && cmdline[i]) //skip whitespace
            i++;
        if (cmdline[i])
        {
            wdlen = makeword(&cmdline[i]);
            ft_printf("wdlen:%d ", wdlen);
            newnode = tokenize(&cmdline[i], wdlen);
            ft_tknadd_back(lst_head, newnode);
            i += wdlen; // check if it is an env variable
        }
    }
    //ft_printf("Whole command line: %s\n", cmdline);
    return (0);
}
