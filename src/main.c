/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/22 14:15:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    initsh(t_msh *msh)
{
    msh->line = (char *)malloc(sizeof(char));
    msh->exit = 0;
    msh->ret = 0;
    return ;
}

int action(char *cmdline)
{
    if (strncmp(cmdline, "^\\", 2))
        ft_printf("%s\n", cmdline);
    return (0);
}

void    handleline(t_msh *msh)
{
    // if (read(0, msh->line, 1) == 0) //ctrl-D
    //     msh->exit = 1;
    if (msh->line)
    {
        free(msh->line);
        msh->line = (char *)NULL;
    }
    msh->line = readline("minishell$");
    if (msh->line && *msh->line)
        add_history(msh->line);
    if (msh->line && !ft_strncmp(msh->line, "exit", ft_strlen(msh->line)))
        msh->exit = 1;
    if (msh->line)
        action(msh->line);
    else
        msh->exit = 1; // currently also quiting on ENTER input

    // if (!ft_strncmp(msh->line, "-1", 2))
    // {
    //     msh->exit = 1;
    // }
    return ;
}

void    c_handler()
{
    ft_printf("\nminishell$");
    return ;
}

void    q_handler()
{
    return ;
}

int main(int ac, char **av, char **envp)
{
    if ((ac != 1) || !envp[0] || !envp)
        ft_printf("Error: Exiting.\n");
    (void)av;
    (void)envp;
    t_msh msh;
    initsh(&msh);
    signal(2, c_handler); //ctrl-C SIGINT
    //signal(3, q_handler); //ctrl-D SIGQUIT

    while (msh.exit == 0)
    {
        handleline(&msh);
    }
    //freeall(&msh);
    return (msh.ret);
}