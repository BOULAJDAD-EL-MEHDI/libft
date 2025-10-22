/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:46:30 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/15 10:00:56 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	int	i;
		
	str1 = (unsigned char ) src;
	str2 = (unsigned char ) dest;
	i = 0;
	while(i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (str2);
}

int main() {
    char source_str[] = "Hello, world!";
    char destination_str[20]; // Ensure enough space

    // Copy 14 bytes (including the null terminator) from source_str to destination_str
    ft_memcpy(destination_str, source_str, strlen(source_str) + 1);

    printf("Source: %s\n", source_str);
    printf("Destination: %s\n", destination_str);

    int source_arr[] = {10, 20, 30, 40, 50};
    int destination_arr[5];

    // Copy 5 integers (each sizeof(int) bytes) from source_arr to destination_arr
    ft_memcpy(destination_arr, source_arr, 5 * sizeof(int));

    printf("Source Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", source_arr[i]);
    }
    printf("\n");

    printf("Destination Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", destination_arr[i]);
    }
    printf("\n");

    return 0;
}
