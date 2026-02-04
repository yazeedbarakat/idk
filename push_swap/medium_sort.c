/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:57:04 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/04 17:34:43 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_extend(stack **a, stack **b, int start, int end)
{
	int	size;
	int	pushed;
	int	mid;
	int	ind;

	size = get_size(*a);
	pushed = 0;
	mid = (start + end) / 2;
	while (size-- && pushed < (end - start))
	{
		ind = (*a)->index;
		if (ind >= start && ind < end)
		{
			pb(a, b);
			if (ind < mid)
				rb(b);
			pushed++;
		}
		else
			ra(a);
	}
}

void	push_back_b(stack **a, stack **b)
{
	int	max;
	int	pos;
	int	size;

	size = get_size(*b);
	max = get_max(b);
	pos = get_pos(b, max);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
	else
	{
		while (pos-- > 0)
			rb(b);
	}
	pa(a, b);
}

void	medium_sort(stack **a, stack **b)
{
	int	start;
	int	end;
	int	ranges;
	int	range_size;
	int	i;

	if (!a || !*a)
		return ;
	index_stack(*a);
	if (get_size(*a) <= 100)
		ranges = 5;
	else
		ranges = 9;
	range_size = get_size(*a) / ranges;
	if (range_size < 1)
		range_size = 1;
	i = 0;
	while (i < ranges)
	{
		start = i * range_size;
		end = start + range_size;
		sort_extend(a, b, start, end);
		i++;
	}
	while (get_size(*b) > 0)
		push_back_b(a, b);
}
