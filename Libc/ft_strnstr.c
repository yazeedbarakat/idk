#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t n)
{
	const char	*sa;
	const char	*sb;
	const char	*ta;
	const char	*ab;
	size_t	sn;

	sa = a;
	sb = b;
	if (*b == '\0')
		return ((char *)a);
	while (*sa != '\0' && n > 0)
	{
		if (*sa != '\0' && *sa != *b)
		{
			sa++;
			sb = b;
			n--;
		}
		ta = sa;
		ab = sa;
		sn = n;
		while (*ab != '\0' && *ab == *sb && sn > 0)
		{
			ab++;
			sb++;
			sn--;
		}
		if (*sb == '\0')
			return ((char *)ta);
		sa++;
		sb = b;
		n--;
	}
	return (NULL);
}
