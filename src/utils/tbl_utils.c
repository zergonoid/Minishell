/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tbl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:40:21 by skioridi          #+#    #+#             */
/*   Updated: 2024/10/23 20:10:50 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"


t_command_table *table_new(char **args, int redir_no, t_token *redirections)
{
    t_command_table *node;

    node = (t_command_table *)malloc(sizeof(t_command_table));
    if (!node)
        return (NULL); // Error?
    node->arguments = args;
    node->builtin_select = builtin_select(args[0]); // Sending the first one as a builtin, to be checked
    node->heredoc_file = NULL;
    node->redir_number = redir_no;
    node->redirections = redirections;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}


void    table_addback(t_command_table **tbl_head, t_command_table *new)
{
    t_command_table *temp;

    temp = *tbl_head;
    if (!*tbl_head)
    {
        *tbl_head = new;
        return ;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}

void    table_clear(t_command_table **tbl_head)
{
    t_command_table *temp;


	while (*tbl_head && (*tbl_head)->next)
	{
		temp = (*tbl_head)->next;
        token_clear(&(*tbl_head)->redirections); // Clearing t_token *struct
		if ((*tbl_head)->arguments)
			ft_free_matrix((*tbl_head)->arguments);
		if ((*tbl_head)->heredoc_file)
			free((*tbl_head)->heredoc_file);
		free(*tbl_head);
		*tbl_head = NULL;
		*tbl_head = temp;
	}
	if (*tbl_head)
	{
		if ((*tbl_head)->arguments)
			ft_free_matrix((*tbl_head)->arguments);
	}
	free(*tbl_head);
	free(tbl_head);
	tbl_head = NULL;
}
