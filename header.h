/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:50:42 by skioridi          #+#    #+#             */
/*   Updated: 2023/12/07 16:12:15 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

typedef struct s_name
{
	int		content;
	int 		index;
	struct s_stack *next;
	struct s_stack	*prev;
}			t_name;

