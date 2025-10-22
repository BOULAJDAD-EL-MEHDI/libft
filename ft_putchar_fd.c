/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:27:24 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/22 15:02:37 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main()
{
	ft_putchar_fd('a', 1);
	return 0;
}
