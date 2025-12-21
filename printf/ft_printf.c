/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:13:28 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/21 18:53:09 by ybarakat         ###   ########.fr       */
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

int	ft_printf(const char *a, ...)
{
	va_list		args;
	void		*save;
	int		counter;
	unsigned int	n;

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
				counter += nbr_count_print(va_arg(args, int));
			else if (*a == 's')
			{
				save = va_arg(args, char *);
				if (!save)
				{
					write (1, "(null)", 6);
					counter += 6;
				}
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
				{
					write (1, "(nil)", 5);
					counter += 5;
				}
				else
				{
					print_hex((unsigned long)save, *a);
					counter += 2 + hex_counter((unsigned long)save);
				}
			}
			else if (*a == 'u')
				counter += unbr_count_print(va_arg(args, unsigned int));
			else if (*a == 'x' || *a == 'X')
			{
				n = va_arg(args, unsigned int);
				print_hex(n, *a);
				counter += hex_counter(n);
			}
			else if (*a == '%')
			{
				write (1, a, 1);
				counter++;
			}
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
