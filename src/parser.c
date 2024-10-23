/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:07:16 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/23 20:27:37 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


t_command_table *initialize_table(t_parser *parser_struct)
{
    char **arguments;
    int i;
    int arg_no;
    t_token *temp;

    i = 0;
    (void)temp;
    (void)i;
    // rm_redirections(parser_struct); // N sei what this is
    arg_no = count_arguments(parser_struct->lst_head);
    arguments = ft_calloc(arg_no + 1, sizeof(char *));
    if (!arguments)
        ft_error(4, parser_struct->msh); // parser_error?? WHY porque
    temp = parser_struct->lst_head;
    while (arg_no > 0)
    {
        arg_no--;
    }
    return (table_new(arguments, parser_struct->redir_number, parser_struct->redirections));
}

t_parser initialize_parser_struct(t_token *lst_head, t_msh *msh)
{
    t_parser    parser_struct;

    parser_struct.lst_head = lst_head;
    parser_struct.redirections = NULL;
    parser_struct.redir_number = 0;
    parser_struct.msh = msh;
    return (parser_struct);
}

int parser(t_msh *msh)
{
    t_command_table *node;
    t_parser        parser_struct;

    msh->cmd_tbl = NULL;
    count_pipes(msh->lst_head, msh); // Counts the no of pipes
    ft_printf("Entering in parser\n");
    if (msh->lst_head->type == PIPE)
    {
        ft_printf("No of pipes: %d\n", msh->pipes);
        return (1); // DOUBLE TOKEN ERROR??????? WHAT IS THIS
    }
    while (msh->lst_head) // E isto que ta fodido
    {
        if (msh->lst_head && msh->lst_head->type == PIPE)
            token_delone(&msh->lst_head, msh->lst_head->i);
        //if (handle_pipe_errors???????(msh, msh->lst_head->type))
        //    return (EXIT_FAILURE);
        parser_struct = initialize_parser_struct(msh->lst_head, msh);
        ft_printf("No of redirections: %d\n", parser_struct.redir_number);
        node = initialize_table(&parser_struct);
        if (!node)
            ft_error(4, parser_struct.msh); // Parser_error?
        if (!msh->cmd_tbl)
            msh->cmd_tbl = node;
        else
            table_addback(&msh->cmd_tbl, node);
        msh->lst_head = parser_struct.lst_head;
        break ; 
    }
    return (EXIT_SUCCESS); 
}
