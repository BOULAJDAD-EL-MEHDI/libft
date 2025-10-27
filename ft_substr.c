/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:33:09 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/27 13:45:16 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		ret = malloc(1);
		if (ret)
			ret[0] = '\0';
		return (ret);
	}
	if (len > s_len - start)
		len = s_len - start;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
