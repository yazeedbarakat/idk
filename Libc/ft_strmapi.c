#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	size_t	i;

	if (!s || !f)
		return (NULL);
	a = malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i] != '\0')
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
/*
#include <stdio.h>
#include "libft.h"

// Example function used by ft_strmapi
char    my_func(unsigned int i, char c)
{
    return (c + i);
}

int main(void)
{
    char *result;

    result = ft_strmapi("abcd", my_func);
    if (result)
    {
        printf("Result: %s\n", result);
        free(result);
    }
    else
        printf("ft_strmapi returned NULL\n");

    return 0;
}
*/
