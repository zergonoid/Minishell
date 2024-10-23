/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:54:41 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 20:16:32 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"


int count_arguments(t_token *lst_head)
{
    t_token *temp;
    int i;

    if (!lst_head)
        return (0);
    i = 0;
    temp = lst_head;
    while (temp && temp->type != PIPE)
    {
        if (temp->i >= 0) // WHy do we do this check
            i++;
        temp = temp->next;
    }
    return (i);
}

void    count_pipes(t_token *lst_head, t_msh *msh)
{
    t_token *temp;

    temp = lst_head;
    msh->pipes = 0;
    while (temp)
    {
        if (temp->type == PIPE)
            msh->pipes++;
        temp = temp->next;
    }
}
