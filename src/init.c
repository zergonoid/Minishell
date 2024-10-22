/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/22 18:17:42 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_msh    *init_msh(t_msh *msh)
{
    signal_init();
    msh->line = (char *)malloc(sizeof(char));
    msh->exit = 0;
    msh->ret = 0;
    msh->lst_head = (t_token *)malloc(sizeof(t_token));
    msh->lst_head = NULL;
    msh->envp = NULL;
    return (msh);
}
