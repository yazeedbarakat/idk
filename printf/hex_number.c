/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:31:53 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/21 18:03:16 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long n, char let)
{
	char	*set;

	if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	set = "0123456789abcdef";
	if (let == 'p')
	{
		write (1, "0x", 2);
		let = 'x';
	}
	else if (let == 'X')
		set = "0123456789ABCDEF";
	if (n >= 16)
		print_hex(n / 16, let);
	ft_putchar_fd(set[(n % 16)], 1);
}

int	hex_counter(unsigned long n)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n > 0)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}
