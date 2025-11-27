int	ft_memcmp(const void *a,const void *b,size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	sa = (const unsigned char *)a;
	sb = (const unsigned char *)b;
	while (n > 0)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		n--;
		sa++;
		sb++;
	}
	return (0);
}
