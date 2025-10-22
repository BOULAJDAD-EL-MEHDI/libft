#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	size_t	i;
	i = 0;
	while (s[i])
		i++;
	return i;
}

static int      is_in_set(char c, char const *set)
{
        size_t  i;

        i = 0;
        while (set[i])
        {
                if (set[i] == c)
                        return (1);
                i++;
        }
        return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
        char    *str;
        size_t  start;
        size_t  end;
        size_t  i;

        if (!s1 || !set)
                return (NULL);
        start = 0;
        while (s1[start] && is_in_set(s1[start], set))
                start++;
        end = ft_strlen(s1);
        while (end > start && is_in_set(s1[end - 1], set))
                end--;
        str = malloc((end - start + 1) * sizeof(char));
        if (!str)
                return (NULL);
        i = 0;
        while (start < end)
        {
                str[i] = s1[start];
                i++;
                start++;
        }
        str[i] = '\0';
        return (str);
}

int main()
{
	char	*ptr;

	ptr = ft_strtrim("asasassssaaamehdi boulajdadasaassaas", "as");
	printf("the return value is : %s", ptr);
	return 0;
}

