/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:49:36 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/19 09:10:27 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    *ft_memset(void *s, int c, size_t n)
{
        char    *str;
        int     i;

        i = 0;
        str = s;
        while (i < n)
        {
                str[i] = c;
                i++;
        }
        return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

int main(void)
{
    int *int_arr;
    char *char_arr;
    size_t i;

    // === Test 1: allocate int array ===
    int_arr = ft_calloc(5, sizeof(int));
    if (!int_arr)
    {
        printf("ft_calloc failed for int array\n");
        return 1;
    }

    printf("=== Test 1: int array (5 * sizeof(int)) ===\n");
    for (i = 0; i < 5; i++)
        printf("int_arr[%zu] = %d\n", i, int_arr[i]);
    printf("\n");

    // === Test 2: allocate char array ===
    char_arr = ft_calloc(10, sizeof(char));
    if (!char_arr)
    {
        printf("ft_calloc failed for char array\n");
        free(int_arr);
        return 1;
    }

    printf("=== Test 2: char array (10 * sizeof(char)) ===\n");
    for (i = 0; i < 10; i++)
        printf("char_arr[%zu] = %d\n", i, char_arr[i]);
    printf("As string: '%s'\n", char_arr); // should print empty string
    printf("\n");

    // === Test 3: check if memory is truly zeroed ===
    int all_zero = 1;
    for (i = 0; i < 10; i++)
    {
        if (char_arr[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }
    printf("=== Test 3: Memory zero check ===\n");
    if (all_zero)
        printf("✅ Memory is fully zeroed.\n");
    else
        printf("❌ Memory is not zeroed.\n");

    // Clean up
    free(int_arr);
    free(char_arr);

    return 0;
}
