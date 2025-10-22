/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bezero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:12:55 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/14 13:44:26 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void    *ft_memset(void *s, int c, size_t n)
{
        char    *str;
	size_t     i;

       	i = 0;
        str = s;
        while (i < n)
	{
		str[i] = c;
		i++;
	}
        return (str);
}

void    ft_bzero(void *s, size_t n)
{
	    ft_memset(s, '\0', n);
}

int main() {
    char buffer[10];

    // Initialize buffer with some values
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A' + i;
    }
    printf("Buffer before bzero: %s\n", buffer);

    // Set the first 5 bytes of buffer to zero
    ft_bzero(buffer, 5);
    printf("Buffer after bzero: %s\n", buffer); // Note: Only prints up to the first null byte

    return 0;
}
