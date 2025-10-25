/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:02:54 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/25 10:13:26 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (unsigned char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
