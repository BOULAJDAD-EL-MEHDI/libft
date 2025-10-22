/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:07:48 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/20 16:19:17 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s1[i])
		i++;
	ptr = malloc(i);
	if (!ptr)
		return NULL;
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	return ptr;
}

char	char_in_str(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	while (char_in_str(set, s1[i]))
		i++;
	j = ft_strlen((char *)s1) - 1;
	printf("the value of i is : %ld || the value of j is : %ld \n", i, j);
	while (char_in_str(set, s1[j]))
		j--;
	printf("the value of i is : %ld || the value of j is : %ld \n", i, j);
	ptr = malloc((j - i + 1) * sizeof(char));
	if (!ptr)
		return NULL;
	k = 0;
	while (i <= j)
	{
		ptr[k] = s1[i];
		i++;
		k++;
	}
	ptr[k] = '\0';
	printf("the value of i is : %ld || the value of j is : %ld \n", i, j);
	return ptr;
}

int main()
{
	char	*ptr;

	ptr = ft_strtrim("aabbababamehdiabababbba", "ab");
	printf("the string is : %s \n", ptr);
	return 0;
}

