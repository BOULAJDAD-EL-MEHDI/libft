/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:02:54 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/16 15:14:20 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int	i;

	i = 0;
	ptr = (unsigned char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return ptr;
		ptr++;
		i++;
	}
	return NULL;
}

int main()
{
	char	*x;
	x = ft_strchr("mehdi boulajdad is the best",'x');
	printf("the value is %c ", *x);
	return 0;
}


