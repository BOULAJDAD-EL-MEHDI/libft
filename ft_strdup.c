/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:15:57 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/29 11:31:15 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *)malloc(sizeof(char ) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, i);
	ptr[i] = '\0';
	return (ptr);
}
