/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:28:23 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/16 08:56:16 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	unsigned char	*dst;
	unsigned char	*sr;

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
	return len;
}

int main(void)
{
    char src1[] = "Hello";
    char src2[] = "HelloWorld";
    char src3[] = "";
    char dst[20];
    size_t len;

    printf("=== Test 1: Normal copy (enough space) ===\n");
    len = ft_strlcpy(dst, src1, sizeof(dst));
    printf("Source: '%s' | Copied: '%s' | Returned len: %zu\n", src1, dst, len);

    printf("\n=== Test 2: Truncation case ===\n");
    len = ft_strlcpy(dst, src2, 6); // size = 6, only 5 chars + '\0'
    printf("Source: '%s' | Copied: '%s' | Returned len: %zu\n", src2, dst, len);
    printf("Truncated? %s\n", (len >= 6) ? "YES" : "NO");

    printf("\n=== Test 3: Exact fit (size = src_len + 1) ===\n");
    len = ft_strlcpy(dst, src1, strlen(src1) + 1);
    printf("Source: '%s' | Copied: '%s' | Returned len: %zu\n", src1, dst, len);

    printf("\n=== Test 4: size = 0 (no space to copy) ===\n");
    len = ft_strlcpy(dst, src1, 0);
    printf("Source: '%s' | Returned len: %zu | dst content may be garbage\n", src1, len);

    printf("\n=== Test 5: Empty source string ===\n");
    len = ft_strlcpy(dst, src3, sizeof(dst));
    printf("Source: '%s' | Copied: '%s' | Returned len: %zu\n", src3, dst, len);

    return 0;
}
