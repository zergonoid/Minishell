/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:09:54 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 20:06:53 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h" // DONE

void    change_path(t_msh *msh)
{
    char *temp;

    temp = ft_strdup(msh->pwd);
    free(msh->old_pwd);
    msh->old_pwd = temp;
    free(msh->pwd);
    msh->pwd = getcwd(NULL, sizeof(NULL));
}

char *find_dir_path(char *s, t_msh *m)
{
    int i;
    
    i = 0;
    while (m->envp[i])
    {
        if (!strncmp(m->envp[i], s, ft_strlen(s)))
            return (ft_substr(m->envp[i], ft_strlen(s), ft_strlen(m->envp[i] - ft_strlen(s)))); // why is it that?
        i++;
    }
    return (NULL); // not found
}

int set_dir_path(t_msh *msh, char *path)
{
    int ret_val;
    
    ret_val = chdir(find_dir_path(path, msh));
    if (ret_val)
    {
        path = ft_substr(path, 0, ft_strlen(path) - 1); //WHY IS THIS
        // ft_putstr_fd(str, STDERR_FILENO);
        // free(str);
        // ft_putendl_fd(" failed", STDERR_FILENO); // Why are these also here
    }
    return (ret_val);
}

int builtin_cd(t_msh *msh, t_command_table *command)
{
    int ret_val;

    ret_val = 0;
    if (!command->arguments[1])
        ret_val = set_dir_path(msh, "HOME=");
    else if (!ft_strncmp((command->arguments[1]), "-", 1))
        ret_val = set_dir_path(msh, "OLDPWD=");
    else
    {
        ret_val = chdir(command->arguments[1]);
        if (ret_val != 0)
        {
            ft_putstr_fd("minishell: ", STDERR_FILENO);
            ft_putstr_fd(command->arguments[1], STDERR_FILENO);
            perror(" ");
        }
    }
    if (ret_val != 0)
        return (EXIT_FAILURE);
    change_path(msh);
    // add_path_to_env(msh); // adding the path back to the environment variables that we have on msh->envp
    return (EXIT_SUCCESS);
}
