/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/08/29 12:12:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_msh    *initsh(t_msh *msh)
{
    msh->line = (char *)malloc(sizeof(char));
    msh->exit = 0;
    msh->ret = 0;
    return (msh);
}

void    handleline(t_msh *msh)
{
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
    else if (msh->line && (!ft_strncmp(msh->line, "-1", 2)))
        msh->exit = 1;
    else if (!msh->line)
        msh->exit = 1;
    else
        lexer(msh->line);
    return ;
}

void    c_handler()
{
    ft_printf("\nminishell$");
    return ;
}

void    q_handler()
{
    ft_printf("minishell$");
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
    signal(3, q_handler); //ctrl-\ SIGQUIT

    while (msh.exit == 0)
    {
        handleline(&msh);
    }
    //freeall(&msh);
    return (msh.ret);
}