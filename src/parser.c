/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:38 by marvin            #+#    #+#             */
/*   Updated: 2024/09/13 15:49:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char *rmquotes(char **s)
{
    char *word = *s;
    int i = 0;
    int save = 0;
    
    if (ft_strchr(&word[i], '"')) // NULL when no " -- POSITION of " when yes
    {
        while (word[i] != '"')
            i++;
        save = i + 1;
        if (ft_strchr(&word[save], '"'))
        {
            while(word[i + 1])
            {
                if (word[i + 1] == '"')
                {
                    i++;
                    word[i] = word[i + 1];
                }
                else
                {
                    word[i] = word[i + 1];
                    i++;
                }
            }
            while (word[i])
                word[i++] = '\0';
        }
    }
    return (word);
}
// CHECK AGAIN IF AFTER REMOVING QUOTES,
// THERE IS AN ENVIRONMENT VARIABLE
// IF THE QUOTES WERE SINGULAR, 
// DO NOT CHECK AGAIN.

int quotehandle(t_token **tkn)
{
    t_token *cur = *tkn;
    char *s = cur->content;
    if (s[0] == '"' || s[0] == '\'')
    {
        char *s_noquotes = rmquotes(&s);
        ft_printf("%s\n", s_noquotes);
        if (s_noquotes[0] == '$' && s[0] == '"')
        {
            if (checkifenv(&s_noquotes[1]))
                cur->type = ENVVAR;
        }
    }
    return (1);
}
