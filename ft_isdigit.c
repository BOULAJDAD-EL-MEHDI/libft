/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:51:15 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/14 08:47:29 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_isdigit(int x)
{
	if (x >= '1' && x <= '9')
		return 1;
	return 0;
}

int main(void)
{
	int i;
	i = ft_isdigit('.');
	if (i)
		printf("it is digit !");
	else 
		printf("it's not digit ");
	return 0;
}
