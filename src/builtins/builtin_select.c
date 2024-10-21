/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:46:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/21 19:32:00 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// function to be used as function pointer, in order to call
// the right function for each case, and get the builtin executed
/*

int     (*builtin_select(char *str))(t_msh *msh, t_CMD *command)
{
    static builtins[7][2] = {
        {"echo", b_echo},
        {"cd", b_cd},
        {"pwd", b_pwd},
        {"export", b_export},
        {"unset", b_unset},
        {"env", b_env},
        {"exit", b_exit}
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

*/