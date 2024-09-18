/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/09/18 18:55:13 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int    handleline(t_msh *msh)
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
    else if (msh->line)
        lexer(msh->line, msh->lst_head);
    else
        return (1);
    return (0);
}

void    c_handler()
{
    ft_printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
    rl_redisplay();
    return ;
}


int main(int ac, char **av, char **envp)
{
    (void)av;
    t_msh msh;
    int flag;

    msh.env = copy_matrix(envp);
    flag = 0;
    if ((ac != 1) || !envp[0] || !envp)
        ft_printf("Error: Exiting.\n");
    init_all(&msh);
    signal(2, c_handler); //ctrl-C SIGINT
    signal(3, SIG_IGN); //ctrl-\ SIGQUIT
    while (msh.exit == 0 && !flag)
    {
        flag = handleline(&msh);
    }
    free_and_exit(&msh);
    return (msh.ret);
}
