/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:16:34 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/03 12:31:58 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int num, int pos)
{
	return ((num >> pos) & 1);
}

int	get_size(stack *a)
{
	stack	*temp;
	int	s_size;

	if (!a)
		return (0);
	temp = a;
	s_size = 0;
	while (temp)
	{
		s_size++;
		temp = temp->next;
	}
	return (s_size);
}

int	get_max_value(stack **a)
{
	int	max;
	stack	*temp;

	if (!a || !*a)
		return (0);
	temp = *a;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	get_max_bits(stack **a)
{
	int	max;
	int	bits;

	bits = 0;
	max = get_max_value(a);
	if (max == 0)
		return (1);
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(stack **a, stack **b)
{
	int	max_bits;
	int	bit_pos;
	int	i;
	int	size;

	if (!a || !*a)
		return ;
	max_bits = get_max_bits(a);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		i = 0;
		size = get_size(*a);
		while (i < size)
		{
			if (((*a)->value >> bit_pos) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		bit_pos++;
	}
}
