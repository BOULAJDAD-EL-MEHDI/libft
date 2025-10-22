/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:12:48 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/17 11:45:53 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t	i;

	i = 0;
	ret = (unsigned char *)s;
	while (i < n && ret[i])
	{
		if (ret[i] == (unsigned char)c)
			return (ret + i);
		i++;
	}
	return NULL;
}

int main()
{
	char	*ptr;
	ptr = ft_memchr("mehdi is the best! ", 't', 20);
	printf("the valeu returned is : %c", *ptr);
	return 0;
}
