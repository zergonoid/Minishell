/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:27 by codespace         #+#    #+#             */
/*   Updated: 2024/08/21 16:46:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	makeword(const char *s)
{
	size_t	len;

	len = 0;
    if (strncmp(s[len], "echo", 4) && ft_isspace())
    {
        if (strncmp(s[len], "echo -n", 7))
            return (7);
        else
            return (4);
    }
    //else if (strncmp(s[len], "cd", 2))
	while (s[len] && !ft_isspace(s[len]))
		len++;
	return (len);
}


t_token	*newtoken(char *content)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
    new->type = 0;
	new->next = NULL;
	return (new);
}

int     findtype(char *s)
{
    int type = 0;


    // ft_putstr_fd(char *string_that_failed, int 2);
    return (type);
}

t_token *tokenize(char *str, int wdlen)
{
    t_token *a;

    char *substring = ft_substr(str, 0, wdlen);
    a = newtoken(substring);
    a->type = findtype(substring);// sort type
    return (a);
}

int lexer(char *cmdline)
{
    int i = 0;
    int wdlen = 0;
    t_token *newnode;
    t_token **lst_head = (t_token **)malloc(sizeof(t_token *));

    while (cmdline[i])
    {
        while (ft_isspace(cmdline[i]) && cmdline[i]) //skip whitespace
            i++;
        if (cmdline[i])
        {
            wdlen = makeword(cmdline[i]);
            newnode = tokenize(cmdline[i], wdlen);
            ft_lstadd_back(lst_head, newnode);
            i += wdlen; // check if it is an env variable  
        }
    }
    ft_printf("%s\n", cmdline);
    return (0);
}
