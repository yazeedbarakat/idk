
#include "push_swap.h"

static int	count_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_ftoa(float n)
{
	int	x;
	int	y;

	x = n * 100;
	print_help(x);
	write(2, ".", 1);
	x = x * 100;
	y = n * 10000;
	y = y - x;
	print_help(y);
	if (y % 100 == 0)
		write (2, "0", 1);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = count_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
