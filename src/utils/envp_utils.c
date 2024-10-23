/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:51:09 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 18:08:26 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char    *extract_path(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (!strncmp(envp[i], "PATH=", 5))
            return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5)); // sending them the path line but without "PATH="
        i++;
    }
    return (ft_strdup("\0")); // Giving them a duplicate of a newstring (memory allocated)
}

int     parse_envp(t_msh *msh)
{
    char    *path_temp;
    int     i;

    path_temp = extract_path(msh->envp);
    msh->paths = ft_split(path_temp, ':'); // the path looks like bin::something:user::somethingelse::and:stuff:like:that I think
    free(path_temp);
    i = 0;
    while (msh->paths[i])
    {
        if (ft_strncmp(&msh->paths[i][ft_strlen(msh->paths[i]) - 1], "/", 1)) // if there is no "/" char in end
        {
            path_temp = ft_strjoin(msh->paths[i], "/"); // we add one
            free(msh->paths[i]);
            msh->paths[i] = path_temp;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}
