#include "libft.h"

void	*ft_memchr(const void *a, int c, size_t n)
{
	const unsigned char	*b;

	b = (const unsigned char *)a;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return ((void *)b);
		n--;
		b++;
	}
	return (NULL);
}
