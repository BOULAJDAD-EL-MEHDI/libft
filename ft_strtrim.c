/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:07:48 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/29 14:31:06 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_start(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	int		in_set;

	i = 0;
	while (str[i])
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i++;
	}
	return ((char *)str + i);
}

static char	*find_finish(char const *str, char const *set, char const *start)
{
	size_t	i;
	size_t	j;
	int		in_set;

	i = ft_strlen(str) - 1;
	while (str + i >= start)
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i--;
	}
	if (str + i < start)
		return ((char *)start);
	return ((char *)str + i);
}

static char	*allocate_substr(char const *start, char const *finish)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(finish - start + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start + i <= finish)
	{
		ptr[i] = start[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*start;
	char	*finish;
	char	*ptr;

	if (!s || !set)
		return (NULL);
	start = find_start(s, set);
	finish = find_finish(s, set, s);
	if (!s[0] || finish < start)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
	}
	else
		ptr = allocate_substr(start, finish);
	return (ptr);
}
