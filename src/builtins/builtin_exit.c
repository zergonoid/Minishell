/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:24 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/22 18:50:04 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void    free_msh(t_msh *msh)
{
    ft_free_matrix(msh->paths);
    ft_free_matrix(msh->envp);
    free(msh->line);
    clear_command_tables(&msh->cmd_tbl);
    free(msh->pwd);
    free(msh->old_pwd);
    if (msh->pipes)     //
        free(msh->pid); // Don't know why we have these two: INVESTIGATE
}
int builtin_exit(t_msh *msh, t_command_table *cmd)
{
    (void)cmd;
    (void)msh;
    ft_putendl_fd("exit", STDOUT_FILENO);
    if (cmd->arguments[1] && cmd->arguments[2])
    {
        ft_putendl_fd("minishellL: exit: too many arguments", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    free_msh(msh);
    return (EXIT_SUCCESS);
}