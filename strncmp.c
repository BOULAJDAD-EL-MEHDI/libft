/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:26:35 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/17 09:28:19 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n && ((unsigned char)s1[i] || (unsigned char)s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (unsigned char)s1[i - 1] - (unsigned char)s2[i - 1];
}

int main()
{
	int i;

	i = ft_strncmp("mehdi", "mehdi", 5);
	printf("====> when the strings are equal : %d\n-\n", i);
	i = ft_strncmp("mehdi", "mehd", 5);
        printf("====> when one of the strings is not equal : %d\n-\n", i);
	i = ft_strncmp("mehdi", "MEHDI", 5);
        printf("====> when the strings are mehdi and MEHDI : %d\n-\n", i);
	i = ft_strncmp("mehdi", "mexdi", 3);
        printf("====> when the strings are mehdi and mexdi but n = 3 : %d\n", i);
	return 0;
}
