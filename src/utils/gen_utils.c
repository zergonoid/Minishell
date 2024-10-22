/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:01:39 by msilva-c          #+#    #+#             */
/*   Updated: 2024/10/22 17:09:41 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char **copy_matrix(char **src)
{
    char **dst;
    size_t i;

    i = 0;
    while (src[i] != NULL)
        i++;
    dst = ft_calloc(sizeof(char *), i + 1);
	if (!dst)
		return (NULL);
    i = -1;
    while (src[++i])
    {
        dst[i] = ft_strdup(src[i]); // duplicating each string of the 2d array
        if (!dst[i])
        {
            ft_free_matrix(dst); // effectively setting to NULL if it's the last one, as well
            return (dst);
        }
    }
    dst[i] = NULL;
    return (dst);
}

int skip_quotes(char *str, int i, int *no, int c)
{
    int j;

    j = i + 1;
    *no += 1; // counting the first one
    while (str[j] && str[j] != c)
        j++;
    if (str[j] == c)
        *no += 1; // we found another quote
    return (j - i); // how many characters to skip in order to go beyond the next q
}

int quote_verify(char *str)
{
    int i;
    int q;
    int qq;

    q = 0;
    qq = 0;
    i = -1;
    while (str[++i])
    {
        if (str[i] == '\"')
            i += skip_quotes(str, i, &qq, '\"');
        if (str[i] == '\'')
            i += skip_quotes(str, i, &q, '\'');
    }
    if ((qq > 0 && qq % 2 != 0 ) || (q > 0 && q % 2 != 0))
        return (0); // odd number of quotes, error
    return (1); // passed our test, quotes are in pair number
}
