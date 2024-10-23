/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 18:24:48 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_state g_state;

int    handleline(t_msh *msh)
{
    char *temp;

    msh->line = readline("minishell$");
    temp = ft_strtrim(msh->line, " ");
    free(msh->line);
    msh->line = temp;
    if (!msh->line)
    {
        ft_printf("exit\n"); // Is this for exiting with ctrl-D when no input?
        exit(EXIT_SUCCESS);
    }
    if (msh->line[0] == '\0')
        return (reset_msh(msh));
    add_history(msh->line);
    if (!quote_verify(msh->line))
        return (ft_error(2, msh));
    if (!lexer(msh->line, &msh->lst_head))
        return (ft_error(3, msh));
    parser(msh);

    reset_msh(msh); // The reason I am crashing right here is that I have not initialized command tables at ALL! :)
    return (1);
}

int main(int ac, char **av, char **envp)
{
    t_msh msh;

    if (ac != 1 || av[1])
    {
        ft_printf("Error: Please run without arguments.\n");
        exit(EXIT_SUCCESS);
    }
    msh.envp = copy_matrix(envp);
    get_pwd(&msh);
    init_msh(&msh);
    handleline(&msh);
    return (EXIT_SUCCESS);
}
