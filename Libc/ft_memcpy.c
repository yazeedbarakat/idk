void	*st_memcpy(void *a, void *b, size_t n)
{
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char *)a;
	sb = (unsigned char *)b;
	while (n-- > 0)
		sa++ = sb++;
	return (a);
}
