#include "libc.h"

void	ft_bzero(void *a, size_t n)
{
	ft_memset(a, 0, n);
}
