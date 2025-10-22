/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:09:52 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/22 14:27:08 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        return *c - 32;
    return c;
}


void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

int	main()
{
	char	ptr[20] = "mehdi boulajdad";
	ft_striteri(ptr, to_upper);
	printf("the new string is : %s ", ptr);
	return 0;
}
