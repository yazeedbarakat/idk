/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:57:04 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/04 18:13:02 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_extend(stack **a, stack **b, t_range range, t_bench bench)
{
	int	size;
	int	pushed;
	int	mid;
	int	ind;

	size = get_size(*a);
	pushed = 0;
	mid = ((range -> start) + (range -> end)) / 2;
	while (size-- && pushed < ((range -> end) - (range -> start)))
	{
		ind = (*a)->index;
		if (ind >= range -> start && ind < range -> end)
		{
			pb(a, b, bench);
			if (ind < mid)
				rb(b, bench);
			pushed++;
		}
		else
			ra(a, bench);
	}
}

void	push_back_b(stack **a, stack **b, t_bench bench)
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
			rrb(b, bench);
	}
	else
	{
		while (pos-- > 0)
			rb(b, bench);
	}
	pa(a, b, bench);
}

void	medium_sort(stack **a, stack **b ,t_bench *bench)
{
	t_range	*range;
	int	ranges;
	int	range_size;
	int	i;

	range = malloc(sizeof(t_range));
	if (!a || !(*a) || !range)
		return (NULL);
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
		range -> start = i * range_size;
		range -> end = range -> start + range_size;
		sort_extend(a, b, range, bench);
		i++;
	}
	while (get_size(*b) > 0)
		push_back_b(a, b, bench);
}
