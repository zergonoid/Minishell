/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:56:50 by marvin            #+#    #+#             */
/*   Updated: 2024/08/29 11:56:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int     findtype(char *s)
{
    /*
	if (!strncmp(s, "echo", ft_strlen(s)) || !strncmp(s, "pwd", ft_strlen(s)) || !strncmp(s, "export", ft_strlen(s)) \
            || !strncmp(s, "cd", ft_strlen(s)) || !strncmp(s, "unset", ft_strlen(s)) || !strncmp(s, "env", ft_strlen(s)))
        return ();
	*/
    if (!strncmp(s, "|", ft_strlen(s)))
        return (PIPE);
    else if (!strncmp(s, ">", ft_strlen(s)))
	    return (GREAT);
	else if (!strncmp(s, ">>", ft_strlen(s)))
	    return (GREAT_GREAT);
    else if (!strncmp(s, "<", ft_strlen(s)))
	    return (LESS);
	else if (!strncmp(s, "<<", ft_strlen(s)))
	    return (LESS_LESS);
    return (0);
}

t_token	*newtoken(char *content, int type)
{
	t_token	*new;
	static int 	i = 0; //index for tokens

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
    new->type = type;
	new->i = i++;
	new->next = NULL;
	new->prev = NULL;
	ft_printf("New token: %s$\n", new->content);
	return (new);
}

void	ft_tknadd_back(t_token **lst, t_token *newnode)
{
	t_token *tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newnode;
	newnode->prev = tmp;
}

void	ft_tknclear(t_token **lst)
{
	t_token	*temp;

	while (*lst && (*lst)->next)
	{
		temp = (*lst)->next;
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
	if (*lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
	}
	free(*lst);
	free(lst);
	lst = NULL;
}
