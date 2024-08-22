/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/22 13:38:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main(int ac, char **av, char **envp)
{
    char cmdline[MAXLINE] = ""; //buffer for commands
    ssize_t r_no;
    int i = -1;
    r_no = 0;
    while (1) // exit the shell when receiving ctrl-D, or with command 'exit'
    {
        char *line = readline("minishell$");
        // r_no = read(0, cmdline, MAXLINE);
        // while(++i < r_no)
        //     if (cmdline[i] == '\n')
        //         cmdline[i] = '\0';
        ft_printf("%s %i\n", line, r_no);    
        // if(r_no == 0)
        //     break ;
        // read commandline
        // QUIT CONDITIONS
        //ft_bzero(cmdline, r_no);
    }
    return (0);
}