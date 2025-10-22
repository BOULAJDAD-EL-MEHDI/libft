/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:15:56 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/16 14:20:29 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     ft_tolower(int c)
{
        if (c >= 'A' && c <= 'Z')
                c = c + 32;
        return (c);
}

int main()
{
        char    x;
        x = ft_tolower('a');
        printf("for a : %c ", x);
        x = ft_tolower('z');
        printf("for z : %c ", x);
        x = ft_tolower('A');
        printf("for A : %c ", x);
        x = ft_tolower('Z');
        printf("for Z : %c ", x);
        return 0;
}
