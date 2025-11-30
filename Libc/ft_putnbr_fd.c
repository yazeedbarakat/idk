#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	new_n;

	new_n = n;
	if (new_n < 0)
	{
		write (fd, "-", 1);
		new_n = new_n * -1;
	}
	if (new_n >= 10)
		ft_putnbr_fd(new_n / 10, fd);
	ft_putchar_fd((new_n % 10) + '0', fd);
}
