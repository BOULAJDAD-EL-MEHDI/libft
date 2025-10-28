/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:29 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/28 14:58:49 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	size_t			i;

	sr = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (sr > (unsigned char *)dest)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = sr[n - 1];
			n--;
		}
	}
	return (dest);
}
