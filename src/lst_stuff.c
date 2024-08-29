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

#include "../header.h"

t_token	*newtoken(char *content)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
    new->type = 0;
	new->next = NULL;
	ft_printf("Made new token: %s$\n", new->content);
	return (new);
}

t_token	*ft_tknlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_tknadd_back(t_token **lst, t_token *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_tknlast(*lst)->next = new;
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
