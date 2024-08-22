/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main(int ac, char **av, char **envp)
{
    (void)av;
    (void)envp;
    char *line;
    if (ac == 1)
    {
        while (1) // exit the shell when receiving ctrl-D, or with command 'exit'
        {
            line = readline("minishell$");
            if (line)
                add_history(line);
            ft_printf("%s\n", line);    
            // read commandline
            // Quit when receiving SIGINT CTRL-C
            if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
            {   
                free(line);
                break ;
            }
            free(line);
        }
    }
    else
        ft_printf("Error\n");   
    return (0);
}