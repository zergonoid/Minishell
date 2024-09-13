/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:38 by marvin            #+#    #+#             */
/*   Updated: 2024/09/13 15:49:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *rmquotes(char **s)
// {
//     char *word = *s;
//     int i = 0;
//     int save = 0;
    
//     if (ft_strchr(&word[i], '"')) // NULL when no " -- POSITION of " when yes
//     {
//         while (word[i] != '"')
//             i++;
//         save = i + 1;
//         if (ft_strchr(&word[save], '"'))
//         {
//             while(word[i + 1])
//             {
//                 if (word[i + 1] == '"')
//                 {
//                     i++;
//                     word[i] = word[i + 1];
//                 }
//                 else
//                 {
//                     word[i] = word[i + 1];
//                     i++;
//                 }
//             }
//             while (word[i])
//                 word[i++] = '\0';
//         }
//     }
//     return (word);
// }
