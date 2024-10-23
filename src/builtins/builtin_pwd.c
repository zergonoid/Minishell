/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:08 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 20:16:05 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h" // DONE

int builtin_pwd(t_msh *msh, t_command_table *cmd) // NEED TO DO
{
    (void)cmd;
    ft_putendl_fd(msh->pwd, STDOUT_FILENO);
    return (EXIT_SUCCESS);
}
