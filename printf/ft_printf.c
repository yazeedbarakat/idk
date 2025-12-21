/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:13:28 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/21 20:38:41 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_count_print(int n)
{
	int	save_n;
	int	counter;

	save_n = n;
	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	ft_putnbr_fd(save_n, 1);
	return (counter);
}

int	char_percent(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	string_pointer(char c, va_list args)
{
	void	*save;

	if (c == 's')
	{
		save = va_arg(args, char *);
		if (!save)
			return (write(1, "(null)", 6), 6);
		ft_putstr_fd(save, 1);
		return (ft_strlen(save));
	}
	if (c == 'p')
	{
		save = va_arg(args, void *);
		if (!save)
			return (write(1, "(nil)", 5), 5);
		print_hex((unsigned long)save, 'p');
		return (2 + hex_counter((unsigned long)save));
	}
	return (0);
}

int	numbers(char c, va_list args)
{
	unsigned int	n;

	if (c == 'd' || c == 'i')
		return (nbr_count_print(va_arg(args, int)));
	if (c == 'u')
		return (unbr_count_print(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
	{
		n = va_arg(args, unsigned int);
		print_hex(n, c);
		return (hex_counter(n));
	}
	return (0);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, a);
	while (*a)
	{
		if (*a == '%')
		{
			a++;
			counter += char_percent(*a, args);
			counter += string_pointer(*a, args);
			counter += numbers(*a, args);
		}
		else
		{
			write(1, a, 1);
			counter++;
		}
		a++;
	}
	va_end(args);
	return (counter);
}
