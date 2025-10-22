/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 07:45:38 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/18 13:15:55 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return NULL;
}

int	main()
{
	char	*ptr;
	ptr = ft_strnstr("mehdi", "jkb", 5);
	printf("%s \n", ptr);
	/*ptr = ft_strnstr("mehdi", "mehdi", 5);
        printf("%s \n\n", ptr);
	ptr = ft_strnstr("mehdi", "hdi", 1);
        printf("%s \n\n", ptr);
	ptr = ft_strnstr("mehdi", "ss", 5);
        printf("%s \n\n", ptr);*/
	return 0;
}
