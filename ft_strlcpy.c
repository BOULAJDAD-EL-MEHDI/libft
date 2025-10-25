/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:28:23 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/25 10:06:48 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			len;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	len = 0;
	if (size > 0)
	{
		while (sr[len] != '\0' && len < size - 1)
		{
			dst[len] = sr[len];
			len++;
		}
		dst[len] = '\0';
	}
	while (sr[len] != '\0')
		len++;
	return (len);
}
