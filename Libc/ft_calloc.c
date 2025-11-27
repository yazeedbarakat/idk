#include "libft.h"

void	*calloc(size_t n, size_t s)
{
	void	*a;

	a = malloc(n * s);
	if (!a)
		return (NULL);
	ft_bzero(a, n * s);
	return (a);
}
