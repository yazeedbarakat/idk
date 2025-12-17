/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:13:28 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/17 22:44:19 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	nbr_print_count(int n)
{
	int	save_n;
	int	counter;

	save_n = n;
	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	ft_putnbr_fd(save_n, 1);
	return (counter);
}
void	ft_put_uns_nbr(unsigned int n)
{
	long	new_n;

	new_n = n;
	if (new_n >= 10)
		ft_put_uns_nbr(new_n / 10);
	ft_putchar_fd((new_n % 10) + '0', 1);
}

void	ft_put_base(unsigned long n, unsigned int base, char let)
{
	char	*set;
	
	set = "0123456789abcdef";
	if (let == 'p')
	{
		write (1, "0x", 2);
		let = 'x';
	}
	if (let == 'X')
		set = "0123456789ABCDEF";
	if (n >= base)
		ft_put_base(n / base, base, let);
	if (n == 0)
		ft_putchar_fd('1', 1);
	else
		ft_putchar_fd(set[(n % base)], 1);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	void *	save;
	int	counter;

	counter = 0;
	va_start(args, a);
	while (*a != '\0')
	{
		if (*a == '%')
		{
			a++;
			if (*a == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				counter++;
			}
			else if (*a == 'd' || *a == 'i')
				counter += nbr_print_count(va_arg(args, int));
			else if (*a == 's')
			{
				save = va_arg(args, char *);
				if (!save)
					write (1, "(null)", 6);
				else
				{
					ft_putstr_fd(save, 1);
					counter += ft_strlen(save);
				}
			}
			else if (*a == 'p')
			{
				save = va_arg(args, void *);
				if (!save)
					write (1, "(nil)", 5);
				else
				{
					ft_put_base((unsigned long)save, 16, *a);
					counter += ft_strlen(save);
				}
			}
			else if (*a == 'u')
				ft_put_uns_nbr(va_arg(args, unsigned int));
			else if (*a == 'x' || *a == 'X')
				ft_put_base(va_arg(args, unsigned int), 16, *a);
			else if (*a == 'b')
				ft_put_base(va_arg(args, unsigned int), 2, *a);
			else if (*a == '%')
				write (1, a, 1);
		}
		else
		{
			write (1, a, 1);
			counter++;
		}
		a++;
	}
	return (counter);
}
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret1;
    int ret2;
    char *s = "hello";
    char *null_str = NULL;
    int x = 42;

    printf("=== BASIC TESTS ===\n");
    ret1 = printf("printf  : %c %s %d %i %u %x %X %%\n",
                   'A', s, -42, 42, 42u, 42, 42);
    ret2 = ft_printf("ft_printf: %c %s %d %i %u %x %X %%\n",
                      'A', s, -42, 42, 42u, 42, 42);
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== POINTER TESTS ===\n");
    ret1 = printf("printf  : %p %p\n", s, NULL);
    ret2 = ft_printf("ft_printf: %p %p\n", s, NULL);
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== STRING NULL TEST ===\n");
    ret1 = printf("printf  : %s\n", null_str);
    ret2 = ft_printf("ft_printf: %s\n", null_str);
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== EDGE INTS ===\n");
    ret1 = printf("printf  : %d %d\n", INT_MAX, INT_MIN);
    ret2 = ft_printf("ft_printf: %d %d\n", INT_MAX, INT_MIN);
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== UNSIGNED EDGE ===\n");
    ret1 = printf("printf  : %u\n", UINT_MAX);
    ret2 = ft_printf("ft_printf: %u\n", UINT_MAX);
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== HEX EDGE ===\n");
    ret1 = printf("printf  : %x %X\n", 0, 0);
    ret2 = ft_printf("ft_printf: %x %X\n", 0, 0);
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== CHAR NULL BYTE TEST ===\n");
    ret1 = printf("printf  : [%c]\n", '\0');
    ret2 = ft_printf("ft_printf: [%c]\n", '\0');
    printf("ret printf    = %d\n", ret1);
    printf("ret ft_printf = %d\n\n", ret2);

    printf("=== BINARY (CUSTOM) ===\n");
    ft_printf("ft_printf: %b %b %b\n", 0, 1, 42);

    printf("=== ADDRESS OF INT ===\n");
    ft_printf("ft_printf: %p\n", &x);

    return 0;
}
