#include "libft.h"

size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*a[];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		a[i] = malloc(word_len(&s[i], c));

