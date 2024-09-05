/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:07:16 by msilva-c          #+#    #+#             */
/*   Updated: 2024/09/04 23:24:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int executor(t_token **lst)
{
    t_token *curr;

    curr = (*lst);
    while (curr->next)
    {
        if (curr->type == CMD)
            execve(curr->content, argv[], envp[]); //(content will have been EXPANDED to PATH)
        // if (curr->type == PIPE)
        //     pipe_handler();
        // if (curr->type == REDIR)
        //     redir()
        curr = curr->next;
    }
    return (0);
}
