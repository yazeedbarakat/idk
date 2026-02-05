/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:16:34 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/05 12:02:42 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *a)
{
	t_stack	*temp;
	t_stack	*min;
	int		ind;

	ind = 0;
	while (1)
	{
		temp = a;
		min = NULL;
		while (temp)
		{
			if (temp->index == -1 && (!min || temp->value < min->value))
				min = temp;
			temp = temp->next;
		}
		if (!min)
			break ;
		min->index = ind;
		ind++;
	}
}

int	get_size(t_stack *a)
{
	t_stack	*temp;
	int		s_size;

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

int	get_max_index(t_stack **a)
{
	int		max;
	t_stack	*temp;

	if (!a || !*a)
		return (0);
	temp = *a;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	get_max_bits(t_stack **a)
{
	int	max;
	int	bits;

	bits = 0;
	max = get_max_index(a);
	if (max == 0)
		return (1);
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_bits;
	int	bit_pos;
	int	i;
	int	size;

	if (!a || !*a)
		return ;
	index_stack(*a);
	max_bits = get_max_bits(a);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		i = 0;
		size = get_size(*a);
		while (i++ < size)
		{
			if (((*a)->index >> bit_pos) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
		}
		while (*b)
			pa(a, b, bench);
		bit_pos++;
	}
}
