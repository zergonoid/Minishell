/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:44 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/18 17:25:28 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    c_handler()
{
    ft_printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
    rl_redisplay();
    return ;
}

void    signal_init(void)
{
    signal(2, c_handler); //ctrl-C SIGINT
    signal(3, SIG_IGN); //ctrl-\ SIGQUIT
}