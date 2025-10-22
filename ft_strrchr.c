/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:29:19 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/16 20:47:28 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return (char *)s;
	return ptr;
}

int main()
{
	char	*ret;
	int i = 0;
	ret = ft_strrchr("el mehdi boulajdad el mehdi", 'm');
	while (ret[i])
	{
		write(1 , &ret[i], 1);
		i++;
	}
	return 0;
}	
