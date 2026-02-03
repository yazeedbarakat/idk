/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:57:04 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/03 19:04:06 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_extend(stack **a, stack **b, int start, int end)
{
	int	size;
	int	pushed;
	int	value;
	int	mid;

	size = get_size(*a);
	pushed = 0;
	mid = (start + end) / 2;
	while (size-- && pushed < (end - start))
	{
		value = (*a)->value;
		if (value >= start && value < end)
		{
			pb(a, b);
			if (value < mid)
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

	max = get_max(b);
	size = get_size(*b);
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
	if (get_size(*a) <= 100)
		ranges = 5;
	else
		ranges = 13;
	range_size = (get_max(a) - get_min(a) + 1) / ranges;
	if (range_size < 1)
		range_size = 1;
	i = 0;
	while (i < ranges)
	{
		start = get_min(a) + (i * range_size);
		end = start + range_size;
		sort_extend(a, b, start, end);
		i++;
	}
	while (get_size(*b) > 0)
		push_back_b(a, b);
}
