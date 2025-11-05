/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:32:22 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/27 14:39:01 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_count(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_allocate(int n, int str_len)
{
	char	*ptr;

	if (n >= 0)
		ptr = (char *)malloc(sizeof(char) * (str_len + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

static char	*ft_fill(long n, int str_len, char *ptr)
{
	ptr[str_len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (str_len > 0 && n > 0)
	{
		ptr[--str_len] = (n % 10) + '0';
		n = n / 10;
	}
	return (ptr);
}

static char	*char_fill(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		str_len;

	if (n == -2147483648 || n == 0)
	{
		ptr = char_fill(n);
		return (ptr);
	}
	else
	{
		str_len = ft_num_count(n);
		ptr = ft_allocate(n, str_len);
		ptr = ft_fill(n, str_len, ptr);
		return (ptr);
	}
}
