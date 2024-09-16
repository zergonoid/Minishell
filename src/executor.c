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

int runthrough(t_token **lst)
{
    t_token *curr;

    curr = (*lst);
    while (curr->next)
    {
        //if (curr->type == CMD)
        //    execve(curr->content, NULL, envp); //(content will have been EXPANDED to PATH)
        // if (curr->type == PIPE)
        //     pipe_handler();
        // if (curr->type == REDIR)
        //     redir()
        curr = curr->next;
    }
    return (0);
}

int expander(t_token **tkn)
{
    t_token *curr = *tkn;

    ft_printf("expander\n");
    while (curr && curr->next)
    {
        if (curr->type == CMD)
        {
            //curr->content = ft_strjoin( , ); // from Mada s pipex, add envpath
        }
        curr = curr->next;
        // if (curr->type = )
    }
    return (0);
}

int executor(t_msh *msh)
{
    ft_printf("executor\\");
    expander(msh->lst_head);

    runthrough(msh->lst_head);
    return (0);
}
