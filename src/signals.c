/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:44 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 18:13:37 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int     event(void)
{
    return (0);
}
void    q_handler(int sig)
{
    ft_putstr_fd("Quit: ", STDERR_FILENO);
    ft_putnbr_fd(sig, STDERR_FILENO);
    ft_putstr_fd("\n", STDERR_FILENO);
}

void    c_handler()
{
    /*
        HEREDOC
        Aqui cenas relacionadas com a possibilidade de haver heredocs
    */
    ft_printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
    rl_redisplay();
    return ;
}

void    signal_init(void)
{
    rl_event_hook = event;
    signal(SIGINT, c_handler); //ctrl-C SIGINT
    signal(SIGQUIT, SIG_IGN); //ctrl-\ SIGQUIT
}