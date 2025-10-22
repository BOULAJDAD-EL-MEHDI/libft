/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:00:21 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/17 15:26:24 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;
	size_t	i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return 0;
}

int	main()
{
	int i;

	i = ft_memcmp("mehdi", "mehdi", 5);
	printf("=====> mehdi || mehdi ->  %d\n\n", i);
	i = ft_memcmp("m", "mehdi", 5);
        printf("=====> mehdi || m ->  %d\n\n", i);
	i = ft_memcmp("mehdi", "mehdx", 4);
        printf("=====> mehdi || mehdx ->  %d\n\n", i);
	i = ft_memcmp("mehdi", "mehdi", 6);
        printf("=====> mehdi || mehdi ->  %d\n\n", i);
	return 0;
}

	
