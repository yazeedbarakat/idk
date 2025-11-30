#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
#include <stdio.h>
#include "libft.h"

void uppercase(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main(void)
{
    char str[] = "hello world";

    ft_striteri(str, uppercase);
    printf("%s\n", str); // HELLO WORLD

    return 0;
}*/
