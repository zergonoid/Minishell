/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:20:27 by codespace         #+#    #+#             */
/*   Updated: 2024/10/23 18:06:23 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int add_node(t_token **lst_head, char *substring, t_type type)
{
    t_token *node;

    node = newtoken(substring, type);
	if (!node)
		return (0);
	ft_tknadd_back(lst_head, node);
	return (1);
}

int	skip_space(char *str, int i)
{
	int j;

	j = 0;
	while (ft_isspace(str[i + j]))
		j++;
	return (j);
}

int 	split_words(char *str, int i, t_token **lst_head)
{
	int j;

	j = 0;
	while (str[i + j] && !(check_type(str[i + j])))
	{
		j += quote_handler(str, i + j, '\"'); // setting a word when we have double quotes
		j += quote_handler(str, i + j, '\''); // setting word when with single quotes
		if (ft_isspace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(lst_head, ft_substr(str, i, j), 0)) // type is 0 bc is word
		return (-1);
    return (j);
}

int	lexer(char *cmdline, t_token **lst_head)
{
	int		i;
	int		j;

	i = 0;
	while (cmdline[i])
	{
		j = 0;
		i += skip_space(cmdline, i);
		if (check_type(cmdline[i]))
			j = handle_types(cmdline, i, lst_head);
		else
			j = split_words(cmdline, i, lst_head);
		if (j < 0) // in all cases of errors, when adding nodes
			return (0);
		i += j; //why are we doing this
	}
	return (1);
}
