/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:54:41 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/22 18:59:47 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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
