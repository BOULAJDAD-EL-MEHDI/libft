/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:45:19 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/22 14:09:20 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

size_t	len_count(char	const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = len_count(s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return NULL;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[len] = '\0';
	return	ptr;
}

int main()
{
	char	*new = ft_strmapi("mehdi", to_upper);
	printf("the new string is %s : ", new);
	return 0;


}
