/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/21 20:10:21 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int    handleline(t_msh *msh)
{
    char *temp;

    msh->line = readline("minishell$");
    temp = ft_strtrim(msh->line, " ");
    free(msh->line);
    msh->line = temp;
    if (!msh->line)
    {
        ft_printf("exit\n");
        exit(0);
    }
    if (msh->line[0] == '\0')
        return (reset_msh(msh));
    add_history(msh->line);
    if (msh->line && !ft_strncmp(msh->line, "exit", ft_strlen(msh->line)))
        return (1);
    else if (msh->line)
    {
        lexer(msh->line, msh->lst_head);
    }
    else
        return (1);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    t_msh msh;

    if (ac != 1 || av[1])
    {
        ft_printf("Error: Please run without arguments.\n");
        exit(0);
    }
    init_msh(&msh);
    msh.env = copy_matrix(envp);
    while (msh.exit == 0)
    {
        msh.exit = handleline(&msh);
    }
    reset_msh(&msh);
    return (0);
}
