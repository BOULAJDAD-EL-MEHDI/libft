/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:04:13 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/18 17:39:31 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;
	int	signe;

	i = 0;
	num = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;

	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * signe);
}

int	main()
{
	int	i;

	i = ft_atoi("mehdi");
	printf("===> the value for mehdi is : %d \n\n", i);
	i = ft_atoi("-1337");
        printf("===> the value for -1337 is : %d \n\n", i);

	i = ft_atoi("+-1337");
        printf("===> the value for +-1337 is : %d \n\n", i);

	i = ft_atoi("+007");
        printf("===> the value for +007 is : %d \n\n", i);
	return 0;
}
