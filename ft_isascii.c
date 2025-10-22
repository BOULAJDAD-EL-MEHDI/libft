/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:01:32 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/14 09:16:18 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_isascii(int x)
{
	if (x >= 0 && x <= 127)
		return 1;
	return 0;
}

int main(void) {
    char ch1 = 'A';
    char ch2 = 0x80; // A non-ASCII character

    if (ft_isascii(ch1)) {
        printf("'%c' is an ASCII character.\n", ch1);
    } else {
        printf("'%c' is not an ASCII character.\n", ch1);
    }

    if (ft_isascii(ch2)) {
        printf("'%c' is an ASCII character.\n", ch2);
    } else {
        printf("'%c' is not an ASCII character.\n", ch2);
    }

    return 0;
}
