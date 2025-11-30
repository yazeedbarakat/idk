#include "libft.h"

size_t	int_size(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	minus(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*a;
	size_t	n_size;
	size_t	i;
	long	nb;

	nb = n;
	n_size = int_size(nb);
	i = minus(n);
	if (nb < 0)
		nb = nb * -1;
	a = malloc(n_size + 1 + i);
	if (!a)
		return (NULL);
	if (i == 1)
		a[0] = '-';
	a[n_size + i] = '\0';
	while (n_size > 0)
	{
		a[n_size - 1 + i] = (nb % 10) + '0';
		nb = nb / 10;
		n_size--;
	}
	return (a);
}
/*
#include <stdio.h>
#include "libft.h"

int main(void)
{
    int test_values[] = {0, 1, -1, 42, -42, 2147483647, -2147483648};
    size_t i;
    char *str;

    for (i = 0; i < sizeof(test_values)/sizeof(int); i++)
    {
        str = ft_itoa(test_values[i]);
        if (str)
        {
            printf("ft_itoa(%d) = \"%s\"\n", test_values[i], str);
            free(str);
        }
        else
            printf("ft_itoa(%d) failed to allocate memory\n", test_values[i]);
    }

    return 0;
}
*/
