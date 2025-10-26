/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:33:34 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/26 15:31:11 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_count(const char *str, char c)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			counter++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (counter);
}

static char	*ft_get_substr(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		start;
	int		j;

	if (!s)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!out)
		return (NULL);
	start = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
		ft_add_word(s, &i, &start, out,  &j);
	out[j] = NULL;
	return (out);
}
