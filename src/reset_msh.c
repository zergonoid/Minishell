/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_msh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:41 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/22 19:08:36 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    clear_command_tables(t_command_table **lst)
{
    t_command_table *temp;
    t_token         *redir_temp;

    if (*lst)
        return ;
    while (*lst)
    {
        temp = (*lst)->next;
        redir_temp = (*lst)->redirections;
        ft_tknclear(&redir_temp);
        if ((*lst)->arguments)
            ft_free_matrix((*lst)->arguments);
        if ((*lst)->heredoc_file)
            free((*lst)->heredoc_file);
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}

void	ft_free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int     reset_msh(t_msh *msh)
{
    ft_printf("Test 4\n");
    clear_command_tables(&msh->cmd_tbl);
    free(msh->line);
    if (msh->pid)       // Don't know again why we do this here
        free(msh->pid); // Which PID were we storing? / when?
    ft_free_matrix(msh->paths);
    init_msh(msh);
    msh->reset = true;
    handleline(msh);
    return (1);
}
