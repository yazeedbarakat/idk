char	*ft_itoa(int n)
{
	char	*a;
	int	nn;
	size_t	c;

	c = 0;
	while (nn > 0)
	{
		nn = nn / 10;
		c++;
	}
	a = malloc(
