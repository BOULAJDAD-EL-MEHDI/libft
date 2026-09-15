/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:33:34 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/29 14:43:23 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_tab(char **tab, size_t filled)
{
	while (filled > 0)
	{
		filled--;
		free(tab[filled]);
	}
	free(tab);
	return (NULL);
}

static size_t	ft_num_words(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == sep)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != sep)
				i++;
		}
	}
	return (count);
}

static char	*ft_fill_word(char *ptr, char const *s, size_t end, size_t len)
{
	size_t	j;

	j = 0;
	while (len > 0)
	{
		ptr[j] = s[end - len];
		j++;
		len--;
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	**fill_tab(char const *s, char sep, char **tab, size_t num_words)
{
	size_t	i;
	size_t	w;
	size_t	len;

	i = 0;
	w = 0;
	len = 0;
	while (w < num_words)
	{
		while (s[i] && s[i] == sep)
			i++;
		while (s[i] && s[i] != sep)
		{
			i++;
			len++;
		}
		tab[w] = (char *)malloc(sizeof(char) * (len + 1));
		if (!tab[w])
			return (free_tab(tab, w));
		ft_fill_word(tab[w], s, i, len);
		len = 0;
		w++;
	}
	tab[w] = 0;
	return (tab);
}

char	**ft_split(char const *s, char sep)
{
	char	**tab;
	size_t	num_words;

	if (!s)
		return (0);
	num_words = ft_num_words(s, sep);
	if (num_words >= (size_t)-1 / sizeof(char *))
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!tab)
		return (0);
	tab = fill_tab(s, sep, tab, num_words);
	return (tab);
}
