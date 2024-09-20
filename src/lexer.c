/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/20 19:56:33 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_token *tokenize(char *str, int start, int wdlen)
{
    t_token *a;

    char *substring = ft_substr(str, start, wdlen);
	printf("substring: %s\n", substring);
    a = newtoken(substring);
    a->type = findtype(substring); // sort type
    return (a);
}

int add_node(t_token **lst_head, char *line, int i, int end)
{
    t_token *last;

    printf("--- adding node ---\n");
    printf("i = %d, end = %d\n", i, end);
    while (i < end)
    {
        printf("%c", line[i]);
        i++;
    }
    printf("$\nadded node\n");
    return (end);
    t_token *newnode = tokenize(line, i, end);
	//printf("is here\n");
    if (!*lst_head)
    {
        *lst_head = newnode;
        return (end);
    }
    last = ft_tknlast(*lst_head);
    last->next = newnode;
    newnode->prev = last;
    ft_tknadd_back(lst_head, newnode);
    return (end);
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

void split_cmds(char *line, int i, int space, t_token **lst_head)
{
	int test = i;
    printf("\n--- entered split_cmds ---\n");
	//while (test < space)
	//	printf("%c", line[test++]);
	//printf("$\n");
    //printf("\n--- starting to split ---\n");
    int flag = 0;
    int start = i;
    while (line[i] && i < space)
    {
    	if (line[i] == '|' || line[i] == '>' || line[i] == '<')
        {
            //printf("space is %d\ni is %d\nstart is %d\n", space, i, start);
			//printf("line[i] = %c\n", line[i]);
            if (i + 1 < space && line[i + 1] && line[i + 1] == line[i])
            {
				if (i > start)
                	add_node(lst_head, line, start, i);
                add_node(lst_head, line, i, i + 2);
                i += 2;
                flag = 0;
                start = i;
            }
            else
            {
				if (i > start)
                	add_node(lst_head, line, start, i);
                add_node(lst_head, line, i, i + 1);
                i += 1;
                flag = 0;
                start = i;

            }
        }
        else
        {
            flag++;
            i++;
        }
    }
    if (flag)
        add_node(lst_head, line, start, i);
    return ;
}

int	quote_handler(char *cmdline, int i, t_token **lst_head)
{
	int		wdlen;

	printf("\n--- entered quote handler ---\n");
	wdlen = strchr_wdlen(&cmdline[i], cmdline[i]);
	if (wdlen)
	{
		//int test = i + wdlen;
		//int ii = i;
		//while (ii < test)
		//	printf("%c", cmdline[ii++]);
		//printf("$\n\n");
		add_node(lst_head, cmdline, i, i + wdlen);
		return (wdlen);
	}
	printf("skipped quote\n");
	return (1);
}


void	final_lexer(char *cmdline, t_token **lst_head)
{
	int		i;
	int start;

	i = 0;
	while (cmdline[i])
	{
		if (cmdline[i] == 39 || cmdline[i] == 34)
			i += quote_handler(cmdline, i, lst_head);
		else if (!ft_isspace(cmdline[i]))
		{
			start = i;
			while (!ft_isspace(cmdline[i]) && cmdline[i])
			{
				if (cmdline[i] == 39 || cmdline[i] == 34)
				{
					if (i > start)
						split_cmds(cmdline, start, i, lst_head);
					i += quote_handler(cmdline, i, lst_head);
					start = i;
				}
				else
					i++;
			}
			if (i > start)
	        	split_cmds(cmdline, start, i, lst_head);
		}
		while (ft_isspace(cmdline[i]) && cmdline[i])
            i++;
	}
	return ;
}
