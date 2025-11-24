#include "libc.h"

void	*ft_memset(void *a, int c, size_t n)
{
	size_t	i;
	unsigned char	*sa;

	sa = (unsigned char *)a;
	i = 0;
	while (i < n)
	{
		*sa++ = (unsigned char)c;
		i++;
	}
	return (a);
}
