/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:44:59 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/21 21:17:30 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int ft_error(int errno, t_msh *msh)
{
    ft_putstr_fd("minishell: ", STDERR_FILENO);
    if (errno == 1)
        ft_putendl_fd("Error: 1 Something went wrong", STDERR_FILENO);
    if (errno == 2)
        ft_putendl_fd("Error: Unclosed quotes", STDERR_FILENO);
    if (errno == 3)
        ft_putendl_fd("Error: 3 Another thing went wrong", STDERR_FILENO);
    reset_msh(msh);
    return (EXIT_FAILURE);
}
