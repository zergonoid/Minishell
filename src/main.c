/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/04/12 13:25:31 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int MAXLINE = 1024;
char prompt[] = "minishell $ ";

int main(int ac, char **av)
{
    char cmdline[MAXLINE]; //buffer for commands

    while (1) // exit the shell when receiving ctrl-D, or with command 'exit'
    {
        ft_printf("%s", prompt);
        // read commandline
    }
    return (0);
}