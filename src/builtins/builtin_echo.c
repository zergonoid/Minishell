/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:30 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/22 18:35:11 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int builtin_echo(t_msh *msh, t_command_table *cmd)
{
    (void)cmd;
    (void)msh;
    // ft_putendl_fd(msh->pwd, STDOUT_FILENO);
    return (EXIT_SUCCESS);
}