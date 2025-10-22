/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:33:09 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/19 10:53:04 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sdtlib.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = malloc(len);
	if (!ret)
		return NULL;
	i = 0;
	while (i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	return (ret);
}

int	main()
{
	char	*ptr;

	ptr = ft_substr("mehdi boulajdad mehdi boulajdad", 7, 14);
	printf("the output is : %s ", ptr);
	return 0;
}
