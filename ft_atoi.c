/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:04:13 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/26 11:01:57 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	long	num;
	int		signe;

	num = 0;
	signe = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		if (num * signe > 2147483647)
			return (2147483647);
		if (num * signe < -2147483648)
			return (-2147483648);
		nptr++;
	}
	return (num * signe);
}


int main(void)
{
    int i;

    i = ft_atoi("0");
    printf("the number is : %d\n", i);

    i = ft_atoi("-0");
    printf("the number is : %d\n", i);

    i = ft_atoi("+958");
    printf("the number is : %d\n", i);

    i = ft_atoi("99999999999999999999");
    printf("the number is : %d\n", i);

    i = ft_atoi("-111111111111111111111");
    printf("the number is : %d\n", i);

    return 0;
}
