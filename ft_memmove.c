/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:29 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/25 18:14:13 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;
	unsigned char	*sr;
	size_t			i;

	ret = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (sr > ret)
	{
		i = 0;
		while (i < n)
		{
			ret[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			ret[n - 1] = sr[n - 1];
			n--;
		}
	}
	return (ret);
}
