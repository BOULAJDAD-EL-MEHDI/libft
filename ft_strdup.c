/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:15:57 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/19 10:31:56 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;

	int	i;
	i = 0;
	while (s[i])
		i++;
	ptr = malloc(i);
	if (!ptr)
		return NULL;
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return ptr;
}

int	main()
{
	char	*ptr;

	ptr = ft_strdup("mehdi boulajdad");
	printf("the string output is : %s \n", ptr);
	return 0;
}
