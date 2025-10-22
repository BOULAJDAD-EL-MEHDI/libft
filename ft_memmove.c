/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:29 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/15 16:44:38 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;
	unsigned char	*sr;
	size_t	i;

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

int main() {
    char arr[] = "abcdefgh";
    printf("Original array: %s\n", arr);

    // Overlapping copy: shift "defgh" to start at index 2 (overwriting "c")
    ft_memmove(arr + 2, arr + 3, 5); // Copy 5 bytes from arr[3] to arr[2]
    printf("After memmove (overlapping): %s\n", arr); // Expected: abdefghh

    char source[] = "Hello World";
    char destination[20];

    // Non-overlapping copy
    ft_memmove(destination, source, strlen(source) + 1); // +1 for null terminator
    printf("Copied to destination: %s\n", destination);

    return 0;
}
