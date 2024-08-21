/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/21 17:36:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main(int ac, char **av, char **envp)
{
    char cmdline[MAXLINE] = ""; //buffer for commands
    ssize_t r_no;
    int i = 0;
    r_no = 0;
    while (1) // exit the shell when receiving ctrl-D, or with command 'exit'
    {
        write(1, "minishell$", 11);
        //while (1)
        //{
            r_no = read(0, cmdline, (size_t)MAXLINE);
            while(cmdline[i])
            {
                if (cmdline[i] == '\n')
                    cmdline[i] = '\0';
                i++;
            }
            ft_printf("%s %i\n", cmdline, r_no);    
            // if(r_no == 0)
            //     break ;
        //}
        
        // read commandline
        // QUIT CONDITIONS
    }
    return (0);
}