/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:02:58 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/16 12:27:23 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len == size)
		return size + src_len;
	while (src[i] && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

int main(void)
{
    char dst1[20] = "Hello";
    char dst2[10] = "Hello";
    char dst3[5]  = "Hi";
    char dst4[20] = "";
    char dst5[10] = "Full";

    size_t len;

    // 1️⃣ Normal case
    len = ft_strlcat(dst1, "World", sizeof(dst1));
    printf("Test1: dst='%s' | return=%zu\n", dst1, len);

    // 2️⃣ Truncation (not enough space)
    len = ft_strlcat(dst2, "BeautifulWorld", sizeof(dst2));
    printf("Test2: dst='%s' | return=%zu\n", dst2, len);

    // 3️⃣ Exact fit
    len = ft_strlcat(dst3, "Yo", sizeof(dst3));
    printf("Test3: dst='%s' | return=%zu\n", dst3, len);

    // 4️⃣ Empty destination
    len = ft_strlcat(dst4, "Start", sizeof(dst4));
    printf("Test4: dst='%s' | return=%zu\n", dst4, len);

    // 5️⃣ Empty source
    len = ft_strlcat(dst5, "", sizeof(dst5));
    printf("Test5: dst='%s' | return=%zu\n", dst5, len);

    return 0;
}
