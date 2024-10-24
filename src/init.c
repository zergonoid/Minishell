/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/23 19:17:58 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int     init_msh(t_msh *msh)
{
    msh->cmd_tbl = NULL;
    msh->lst_head = NULL;
    msh->reset = false;
    msh->pid = NULL;
    msh->heredoc = false;
    g_state.stop_heredoc = 0;
    g_state.in_cmd = 0;
    g_state.in_heredoc = 0;
    parse_envp(msh);
    signal_init();
    return (1);
}

int     prep(t_msh *msh)
{
    signal(SIGQUIT, q_handler);
    g_state.in_cmd = 1; // We are inside
    if (msh->pipes == 0) // No pipes, single cmd
        ft_printf("This will be executed as a single command\n");
    else
    {
        msh->pid = ft_calloc(sizeof(int), msh->pipes + 2); // Why plus 2 here?
        if (!msh->pid) // Protection
            return (ft_error(1, msh)); // Err 1
        //executor(msh);
    }
    g_state.in_cmd = 0;
    return (EXIT_SUCCESS);
}
