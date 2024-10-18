/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/18 17:27:32 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool    handleline(t_msh *msh)
{
    if (msh->line)
    {
        //ft_tknclear(msh->lst_head);
        free(msh->line);
        msh->line = (char *)NULL;
    }
    msh->line = readline("minishell$");
    if (msh->line && *msh->line)
        add_history(msh->line);
    if (msh->line && !ft_strncmp(msh->line, "exit", ft_strlen(msh->line)))
        return (1);
    else if (msh->line)
    {
        printf("\nfull cmdline: %s\n\n", msh->line);
        final_lexer(msh->line, msh->lst_head);
    }
    else
        return (1);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    (void)av;
    t_msh msh;

    if ((ac != 1))
    {
        ft_printf("Error: Exiting.\n");
        exit(0);
    }
    init_all(&msh);
    msh.env = copy_matrix(envp);
    while (msh.exit == 0)
    {
        msh.exit = handleline(&msh);
    }
    free_and_exit(&msh);
    return (0);
}
