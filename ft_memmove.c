/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:29 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/31 11:49:37 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	size_t			i;

	sr = (unsigned char *)src;
	if ((uintptr_t)sr > (uintptr_t)dest)
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
