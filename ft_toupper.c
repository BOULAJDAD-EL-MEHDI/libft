/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:05:27 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/16 14:14:24 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int main()
{
	char	x;
	x = ft_toupper('a');
	printf("for a : %c ", x);
	x = ft_toupper('z');
        printf("for z : %c ", x);
	x = ft_toupper('A');
        printf("for A : %c ", x);
	x = ft_toupper('Z');
        printf("for Z : %c ", x);
	return 0;
}

	
