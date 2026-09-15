/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 07:45:38 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/29 11:00:55 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	len_little = ft_strlen(little);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (j < len - i && big[i + j] && big[i + j] == little[j])
			j++;
		if (j == len_little)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
