/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:27 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/22 18:36:28 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int builtin_env(t_msh *msh, t_command_table *cmd)
{
    int i;

    i = 0;
    (void)cmd;
    while (msh->envp[i])
    {
        ft_putendl_fd(msh->envp[i], STDOUT_FILENO);
        i++;
    }
    return (EXIT_SUCCESS);
}