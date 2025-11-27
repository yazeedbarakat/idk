#include "libft.h"

char	*ft_strdup(const char *a)
{
	char	*b;
	size_t	l;
	size_t	i;

	l = ft_strlen(a);
	b = malloc(l + 1);
	if (!b)
		return (NULL);
	i = 0;
	while (i < l)
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
