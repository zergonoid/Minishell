/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:41 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/21 20:08:49 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
    if (msh->line)
        free(msh->line);
    if (msh->lst_head)
        ft_tknclear(msh->lst_head);
    if (msh->env)
        ft_free_matrix(msh->env);
    handleline(msh);
    return (1);
}
