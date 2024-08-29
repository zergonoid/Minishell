/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:27 by codespace         #+#    #+#             */
/*   Updated: 2024/08/29 13:14:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	makeword(const char *s)
{
	size_t	len;

	len = 0;
    if (!strncmp(&s[len], "echo", 4))
    {
        if (!strncmp(&s[len], "echo -n", 7))
            return (7);
        else
            return (4);
    }
    //else if (strncmp(s[len], "cd", 2))
	while (s[len] && !ft_isspace(s[len]))
		len++;
	return (len);
}

int     findtype(char *s)
{
    int type = 0;
    (void)s;

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
            ft_printf("wdlen %d\n", wdlen);
            newnode = tokenize(&cmdline[i], wdlen);
            ft_tknadd_back(lst_head, newnode);
            i += wdlen; // check if it is an env variable  
        }
        ft_printf("inside\n");
    }
    //ft_printf("Whole command line: %s\n", cmdline);
    return (0);
}
