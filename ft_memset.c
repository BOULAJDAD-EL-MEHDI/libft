/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:17:10 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/14 15:09:00 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int	i;
	
	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c; 
		i++;
	}
	return (str);
}

int main() {
    char str[50] = "This is a test string for memset.";
    printf("Before memset(): %s\n", str);

    // Fill the first 5 characters with '*'
    ft_memset(str, '*', 200);
    printf("After memset (first 5 chars): %s\n", str);

    int numbers[10];
    // Initialize all elements of the integer array to 0
    ft_memset(numbers, 0, sizeof(numbers)); 

    printf("Initialized integer array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
