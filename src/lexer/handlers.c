/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:06:59 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/22 17:09:46 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_type check_type(int c)
{
    static int type_array[3][2] = {
    {'|', PIPE},
    {'>', GREAT},
    {'<', LESS},
    };
    int i;
    
    i = 0;
    while (i < 3)
    {
        if (type_array[i][0] == c)
            return (type_array[i][1]);
        i++;
    }
    return (0); // which means it was just a word/command
}

int handle_types(char *str, int i, t_token **lst_head)
{
    t_type type;

    type = check_type(str[i]);
    if (type == GREAT && check_type(str[i + 1]) == GREAT)
    {
        if (!add_node(lst_head, NULL, GREAT_GREAT))
            return (-1);
        return (2); // was GREAT_GREAT, skipped 2 chars
    }
    else if (type == LESS && check_type(str[i + 1]) == LESS)
    {
        if (!add_node(lst_head, NULL, LESS_LESS))
            return (-1);
        return (2); // was LESS_LESS, skipped 2 chars
    }
    else if (type)
    {
        if (!add_node(lst_head, NULL, type))
            return (-1);
        return (1); // was only PIPE, GREAT or LESS, skipped 1
    }
    return (0);
}

int	quote_handler(char *str, int i, char c)
{
	int		j;

	j = 0;
	if (str[i] == c)
	{
		j++;
		while (str[i + j] != c && str[i + j])
			j++;
		j++;
	}
	return (j);
}