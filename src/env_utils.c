/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:01:39 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/21 19:31:50 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char **copy_matrix(char **src)
{
    char **dst;
    int i = 0;

    while (src[i] != NULL)
        i++;
    dst = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
    i = -1;
    while (src[++i])
        dst[i] = ft_strdup(src[i]);
    dst[i] = NULL;
    return (dst);
}
