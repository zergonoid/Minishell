/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:46:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/22 18:42:17 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// function to be used as function pointer, in order to call
// the right function for each case, and get the builtin executed

int     (*builtin_select(char *str))(t_msh *msh, t_command_table *table)
{
    static void *builtins[7][2] = {
        {"cd", builtin_cd},
        {"echo", builtin_echo},
        {"pwd", builtin_pwd},
        {"export", builtin_export},
        {"unset", builtin_unset},
        {"env", builtin_env},
        {"exit", builtin_exit}
        };
        int i;
        
    i = 0;
    while (i < 7)
    {
        if (str)
        {
            if (!strncmp(builtins[i][0], str, ft_strlen(builtins[i][0])))
                return (builtins[i][1]);
        }
        i++;
    }
    return (NULL);
}
