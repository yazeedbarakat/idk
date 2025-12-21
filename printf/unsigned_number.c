/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:28:53 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/21 18:03:41 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unbr(unsigned int n)
{
	long	new_n;

	new_n = n;
	if (new_n >= 10)
		print_unbr(new_n / 10);
	ft_putchar_fd((new_n % 10) + '0', 1);
}

int	unbr_count_print(unsigned int n)
{
	unsigned int	save_n;
	int		counter;

	save_n = n;
	counter = 0;
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	print_unbr(save_n);
	return (counter);
}
