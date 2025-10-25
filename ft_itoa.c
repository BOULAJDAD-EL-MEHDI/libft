/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:32:22 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/25 11:34:09 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num_count(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_allocate(int n, int str_len)
{
	char	*ptr;

	if (n >= 0)
		ptr = (char *)malloc(sizeof(char) * str_len);
	else if (n < 0)
		ptr = (char *)malloc(sizeof(char) * str_len + 1);
	if (!ptr)
		return (NULL);
}

char	*ft_fill(long n, int str_len, char *ptr)
{
	if (n > 0)
	{
		ptr[str_len] = '\0';
		while (n > 0)
		{
			ptr[str_len - 1] = (n % 10) + '0';
			str_len--;
			n /= 10;
		}
	}
	else
	{
		n = -n;
		ptr[str_len + 1] = '\0';
		while (n > 0)
		{
			ptr[str_len] = (n % 10) + '0';
			str_len--;
			n /= 10;
		}
		ptr[0] = '-';
	}
	return (ptr);
}

char	*char_fill(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = (char *)malloc(sizeof(char) * 12);
		if (!ptr)
			return (NULL);
		ptr = "-2147483648";
	}
	if (n == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 2);
		if (!ptr)
			return (NULL);
		ptr = "0";
	}
	return (ptr);
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
